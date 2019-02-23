#include <gtest/gtest.h>
#include "AcademicPerf.h"
#include "TSortTable.h"
#include "TTreeTable.h"
#include "TBalanceTree.h"
#include "TBalanceNode.h"
#include "TArrayHash.h"
#include "TListHash.h"

//--------TESTING_TTABRECORD--------

TEST(TTabRecord, No_Throw_when_create_default_record)
{
    ASSERT_NO_THROW(TTabRecord());
}

TEST(TTabRecord, Can_Create_Record)
{
    auto data = new AcademicPerformance();
    data->addCourse("AISD", 5);

    ASSERT_NO_THROW(TTabRecord("Matyasov M.A.", data));
    delete data;
}

TEST(TTabRecord, Can_Set_Key)
{
    TTabRecord rec;
    
    ASSERT_NO_THROW(rec.SetKey("Matyasov M.A."));
}

TEST(TTabRecord, Can_Get_Key)
{
    TTabRecord rec;
    std::string key("Matyasov M.A.");
    rec.SetKey(key);

    EXPECT_EQ(rec.GetKey(), key);
}

TEST(TTabRecord, Can_Set_Value)
{
    TTabRecord rec;
    auto data = new AcademicPerformance();
    data->addCourse("AISD", 5);

    ASSERT_NO_THROW(rec.SetValuePtr(data));
    delete data;
}

TEST(TTabRecord, Can_Get_Value)
{
    TTabRecord rec;
    auto data = new AcademicPerformance();
    data->addCourse("AISD", 5);
    rec.SetValuePtr(data);

    EXPECT_EQ(rec.GetValuePTR(), data);
    delete data;
}

TEST(TTabRecord, Can_Get_Record_Copy_If_pValue_Is_Not_nullptr)
{
    auto data = new AcademicPerformance();
    data->addCourse("AISD", 5);
    data->addCourse("OS", 4);
    TTabRecord src("Matyasov M.A", data);
    auto copy = static_cast<PTTabRecord>(src.GetCopy());

    auto src_data = static_cast<AcademicPerformance*>(src.GetValuePTR());
    auto copy_data = static_cast<AcademicPerformance*>(copy->GetValuePTR());
    EXPECT_EQ(*src_data, *copy_data);
    EXPECT_EQ(copy->GetKey(), src.GetKey());
    delete copy;
    delete src_data;
    delete copy_data;
}

TEST(TTabRecord, can_Get_Record_when_pValue_nulla)
{
    TTabRecord src("Matyasov M.A");
    auto copy = static_cast<PTTabRecord>(src.GetCopy());

    EXPECT_EQ(src.GetKey(), copy->GetKey());
    delete copy;
}

TEST(TTabRecord, Can_Assign_Record_To_Itself)
{
    auto data = new AcademicPerformance();
    data->addCourse("AISD", 5);
    data->addCourse("OS", 4);
    TTabRecord rec("Matyasov M.A", data);

    ASSERT_NO_THROW(rec = rec);
    delete data;
}

TEST(TTabRecord, assign_Different_Records)
{
    auto src_data = new AcademicPerformance();
    src_data->addCourse("AISD", 5);
    src_data->addCourse("OS", 4);
    TTabRecord src("Matyasov M.A", src_data);

    TTabRecord dst;
    dst = src;

    auto dst_data = static_cast<AcademicPerformance*>(dst.GetValuePTR());
    EXPECT_EQ(src.GetKey(), dst.GetKey());
    EXPECT_EQ(*src_data, *dst_data);
    delete src_data;
    delete dst_data;
}

TEST(TTabRecord, Equal_Records_Are_Equal)
{
    auto data = new AcademicPerformance();
    data->addCourse("AISD", 5);
    data->addCourse("OS", 4);

    TTabRecord rec1("Matyasov M.A", data);
    TTabRecord rec2("Matyasov M.A", data);

    EXPECT_TRUE(rec1 == rec2);
    delete data;
}

TEST(TTabRecord, Record_Is_Equal_To_Itself)
{
    auto data = new AcademicPerformance();
    data->addCourse("AaDS", 5);
    data->addCourse("OS", 4);

    TTabRecord rec("Ivanov I.I.", data);
    
    EXPECT_TRUE(rec == rec);
    delete data;
}

TEST(TTabRecord, Different_Records_Arent_Equal)
{
    auto data = new AcademicPerformance();
    data->addCourse("AaDS", 5);
    data->addCourse("OS", 4);

    TTabRecord rec1("Ivanov I.I.", data);
    TTabRecord rec2("Petrov P.P.", data);

    EXPECT_FALSE(rec1 == rec2);
    delete data;
}

TEST(TTabRecord, Can_Compare_Records)
{
    TTabRecord rec1("Matyasov M.A");
    TTabRecord rec2("Petrov P.P.");

    EXPECT_TRUE(rec1 < rec2);
    EXPECT_FALSE(rec2 < rec1);
    EXPECT_TRUE(rec2 > rec1);
    EXPECT_FALSE(rec1 > rec2);
}

TEST(TTabRecord, Can_Get_Average_Mark)
{
    AcademicPerformance data;

    data.addCourse("AISD", 5);
    data.addCourse("OS", 5);
    data.addCourse("DB", 4);
    data.addCourse("Physics", 3);

    EXPECT_DOUBLE_EQ(data.getAvgMark(), 4.25);
}

TEST(TTabRecord, Avg_Mark_Can_Be_Equal_To_Zero)
{
    AcademicPerformance data;

    EXPECT_DOUBLE_EQ(data.getAvgMark(), .0);
}

TEST(TTabRecord, Can_Get_Mark_With_Specified_Course)
{
    AcademicPerformance data;
    
    data.addCourse("OS", 5);

    EXPECT_EQ(data.getMark("OS"), 5);
}

TEST(TTabRecord, Mark_Can_Be_Equal_To_Zero)
{
    AcademicPerformance data;

    data.addCourse("OS", 5);

    EXPECT_EQ(data.getMark("AaDS"), 0);
}

TEST(TScanTable, Can_Create_Default_Scan_Table)
{
    ASSERT_NO_THROW(TScanTable t);
}

TEST(TScanTable, Throws_While_Creating_Scan_Table_If_Its_Size_Is_Non_Positive)
{
    ASSERT_THROW(TScanTable t(-5), std::out_of_range);
}

TEST(TScanTable, Throws_While_Creating_Scan_Table_If_Its_Size_Is_Too_Large)
{
    ASSERT_THROW(TScanTable t(TabMaxSize + 1000), std::out_of_range);
}

TEST(TScanTable, Can_Get_Data_Count_In_Scan_Table)
{
    TScanTable t;

    EXPECT_EQ(t.GetDataCount(), 0);
}

TEST(TScanTable, Can_Get_Efficiency_From_Scan_Table)
{
    TScanTable t;

    EXPECT_EQ(t.GetEfficiency(), 0);
}

TEST(TScanTable, Can_Determine_Empty_Scan_Table)
{
    TScanTable t;

    EXPECT_TRUE(t.IsEmpty());
}

TEST(TScanTable, Can_Get_Scan_Table_Size)
{
    TScanTable t;

    EXPECT_EQ(t.GetTabSize(), TabMaxSize);
}

TEST(TScanTable, Can_Insert_Record_Into_Scan_Table)
{
    TScanTable t(1);

    ASSERT_NO_THROW(t.InsRecord("Matyasov M.A", new AcademicPerformance()));
}

TEST(TScanTable, Throws_While_Inserting_Record_Into_Full_Scan_Table)
{
    TScanTable t(1);
    t.InsRecord("Matyasov M.A", new AcademicPerformance());

    ASSERT_THROW(t.InsRecord("Petrov P.P.", new AcademicPerformance()),
        std::runtime_error);
}

TEST(TScanTable,
Throws_While_Inserting_Record_Into_Scan_Table_If_Specified_Key_Already_Exists)
{
    TScanTable t(2);
    t.InsRecord("Matyasov M.A", new AcademicPerformance());

    ASSERT_THROW(t.InsRecord("Matyasov M.A", new AcademicPerformance()),
        std::runtime_error);
}

TEST(TScanTable, Throws_While_Searching_For_A_Record_With_Nonexistent_Key)
{
    TScanTable t(1);
    t.InsRecord("Matyasov M.A", new AcademicPerformance());

    ASSERT_THROW(t.FindRecord("Petrov P.P."), std::runtime_error);
}

TEST(TScanTable, Throws_While_Deleting_Record_From_Empty_Scan_Table)
{
    TScanTable t;

    ASSERT_THROW(t.DelRecord("KEY"), std::runtime_error);
}

TEST(TScanTable,
Throws_While_Deleting_Record_From_Scan_Table_With_Nonexistent_Key)
{
    TScanTable t(1);
    t.InsRecord("Matyasov M.A", new AcademicPerformance());

    ASSERT_THROW(t.DelRecord("Petrov P.P."), std::runtime_error);
}

TEST(TScanTable, Can_Delete_Record_From_Scan_Table)
{
    TScanTable t(1);
    TKey key("Matyasov M.A");
    t.InsRecord(key, new AcademicPerformance());

    ASSERT_NO_THROW(t.DelRecord(key));
    ASSERT_THROW(t.FindRecord(key), std::runtime_error);
}

TEST(TScanTable, Can_Replace_Record_In_Scan_Table)
{
    TScanTable t(1);
    TKey oldKey("Matyasov M.A"), newKey("Petrov P.P.");
    t.InsRecord(oldKey, new AcademicPerformance);

    t.DelRecord(oldKey);
    t.InsRecord(newKey, new AcademicPerformance());

    ASSERT_THROW(t.FindRecord(oldKey), std::runtime_error);
    ASSERT_NO_THROW(t.FindRecord(newKey));
}

TEST(TScanTable, Can_Set_And_Get_Current_Position_In_Scan_Table)
{
    TScanTable t(1);
    t.InsRecord("KEY", new AcademicPerformance());

    ASSERT_NO_THROW(t.SetCurrentPos(0));
    EXPECT_EQ(t.GetCurrentPos(), 0);
}

TEST(TScanTable, Throws_While_Setting_Current_Pos_If_It_Is_Negative)
{
    TScanTable t;

    ASSERT_THROW(t.SetCurrentPos(-1), std::invalid_argument);
}

TEST(TScanTable,
Throws_While_Setting_Current_Pos_If_It_Is_Greater_Than_DataCount)
{
    TScanTable t;
    t.InsRecord("KEY", new AcademicPerformance());

    ASSERT_THROW(t.SetCurrentPos(t.GetDataCount() + 1), std::invalid_argument);
}

TEST(TScanTable, Can_Determine_Full_Scan_Table)
{
    TScanTable t(1);
    t.InsRecord("KEY", new AcademicPerformance());

    EXPECT_TRUE(t.IsFull());
}

TEST(TScanTable, Can_Get_Key_From_Scan_Table_Record)
{
    TScanTable t(1);
    TKey key("Matyasov M.A");
    t.InsRecord(key, new AcademicPerformance());

    EXPECT_EQ(t.GetKey(), key);
}

TEST(TScanTable, Can_Get_PTDatValue_From_Scan_Table)
{
    TScanTable t(1);
    TKey key("Matyasov M.A");
    auto data = new AcademicPerformance();
    data->addCourse("AISD", 5);
    t.InsRecord(key, data);

    auto recievedData = static_cast<AcademicPerformance*>(t.GetValuePTR());
    EXPECT_EQ(*recievedData, *data);
}

TEST(TSortTable, Can_Create_Default_Sort_Table)
{
    ASSERT_NO_THROW(TSortTable t);
}

TEST(TSortTable, Can_Set_Sort_Method)
{
    TSortTable t;
    ASSERT_NO_THROW(t.SetSortMethod(INSERTION_SORT));
}

TEST(TSortTable, Throws_While_Setting_Unsupported_Sort_Type)
{
    TSortTable t;
    ASSERT_THROW(t.SetSortMethod((TSortMethod)3), std::invalid_argument);
}

TEST(TSortTable, Can_Get_Sort_Type)
{
    TSortTable t;
    EXPECT_EQ(t.GetSortMethod(), INSERTION_SORT);
}

TEST(TSortTable, Can_Assign_Scan_Table_To_Sort_Table)
{
    TScanTable scan_t;
    scan_t.InsRecord("Petrov P.P.", nullptr);
    scan_t.InsRecord("Matyasov M.A", nullptr);

    TSortTable sort_t;

    ASSERT_NO_THROW(sort_t = scan_t;);
}

TEST(TSortTable, Throws_While_Searching_For_A_Record_With_Nonexistent_Key)
{
    TScanTable scan_t;
    scan_t.InsRecord("Petrov P.P.", nullptr);
    scan_t.InsRecord("Ivanov I.I.", nullptr);
    scan_t.InsRecord("Abramov A.A.", nullptr);

    TSortTable sort_t(scan_t);

    ASSERT_THROW(sort_t.FindRecord("Merkel A."), std::runtime_error);
}

TEST(TSortTable, Throws_While_Searching_For_A_Record_In_Empty_Sort_Table)
{
    TSortTable sort_t;

    ASSERT_THROW(sort_t.FindRecord("Ivanov I.I."), std::runtime_error);
}

TEST(TSortTable, Can_Find_A_Record_In_Sort_Table)
{
    TScanTable scan_t;
    scan_t.InsRecord("Petrov P.P.", nullptr);
    scan_t.InsRecord("Ivanov I.I.", nullptr);
    scan_t.InsRecord("Abramov A.A.", nullptr);

    TSortTable sort_t(scan_t);

    ASSERT_NO_THROW(sort_t.FindRecord("Ivanov I.I."));
}

TEST(TSortTable, Can_Insert_Record_Into_Sort_Table)
{
    TSortTable sort_t;

    ASSERT_NO_THROW(sort_t.InsRecord("Ivanov I.I.", nullptr));
}

TEST(TSortTable, Throws_While_Inserting_Record_Into_Full_Sort_Table)
{
    TSortTable sort_t(1);
    sort_t.InsRecord("Ivanov I.I.", nullptr);

    ASSERT_THROW(sort_t.InsRecord("Petrov P.P.", nullptr), std::runtime_error);
}

TEST(TSortTable,
Throws_While_Inserting_Record_Into_Sort_Table_If_Specified_Key_Already_Exists)
{
    TSortTable sort_t;
    sort_t.InsRecord("Ivanov I.I.", nullptr);

    ASSERT_THROW(sort_t.InsRecord("Ivanov I.I.", nullptr), std::runtime_error);
}

TEST(TSortTable, Can_Delete_A_Record_From_Sort_Table)
{
    TSortTable sort_t;
    sort_t.InsRecord("Ivanov I.I.", nullptr);

    ASSERT_NO_THROW(sort_t.DelRecord("Ivanov I.I."));
}

TEST(TSortTable, Throws_While_Deleting_A_Record_From_Empty_Sort_Table)
{
    TSortTable sort_t;

    ASSERT_THROW(sort_t.DelRecord("Key"), std::runtime_error);
}

TEST(TSortTable,
Throws_While_Deleting_A_Record_From_Sort_Table_With_Nonexistent_Key)
{
    TSortTable sort_t;
    sort_t.InsRecord("Ivanov I.I.", nullptr);
    
    ASSERT_THROW(sort_t.DelRecord("Key"), std::runtime_error);
}

TEST(TSortTable,
Deleting_A_Record_With_Random_Key_Does_Not_Break_Table_Sorted_State)
{
    TSortTable sort_t;
    sort_t.InsRecord("Petrov P.P.", nullptr);
    sort_t.InsRecord("Ivanov I.I.", nullptr);
    sort_t.InsRecord("Abramov A.A.", nullptr);
    sort_t.InsRecord("Dvorov D.D.", nullptr);

    sort_t.DelRecord("Ivanov I.I.");    // Deleting random record

    // Table is still sorted
    sort_t.Reset();
    EXPECT_EQ(sort_t.GetKey(), "Abramov A.A.");
    sort_t.GoNext();
    EXPECT_EQ(sort_t.GetKey(), "Dvorov D.D.");
    sort_t.GoNext();
    EXPECT_EQ(sort_t.GetKey(), "Petrov P.P.");
}

TEST(TSortTable,
Deleting_A_Record_With_The_Least_Key_Does_Not_Break_Table_Sorted_State)
{
    TSortTable sort_t;
    sort_t.InsRecord("Petrov P.P.", nullptr);
    sort_t.InsRecord("Ivanov I.I.", nullptr);
    sort_t.InsRecord("Abramov A.A.", nullptr);
    sort_t.InsRecord("Dvorov D.D.", nullptr);

    sort_t.DelRecord("Abramov A.A.");    // Deleting record with the least key

    // Table is still sorted
    sort_t.Reset();
    EXPECT_EQ(sort_t.GetKey(), "Dvorov D.D.");
    sort_t.GoNext();
    EXPECT_EQ(sort_t.GetKey(), "Ivanov I.I.");
    sort_t.GoNext();
    EXPECT_EQ(sort_t.GetKey(), "Petrov P.P.");
}

TEST(TTreeNode, Can_Create_Dafault_Tree_Node)
{
    ASSERT_NO_THROW(TTreeNode ttn);
}

TEST(TTreeNode, Can_Get_Left_From_Tree_Node)
{
    TTreeNode left("", nullptr, nullptr, nullptr);
    
    TTreeNode node("", nullptr, &left, nullptr);

    EXPECT_EQ(node.GetLeft(), &left);
}

TEST(TTreeNode, Can_Get_Right_From_Tree_Node)
{
    TTreeNode right("", nullptr, nullptr, nullptr);

    TTreeNode node("", nullptr, nullptr, &right);

    EXPECT_EQ(node.GetRight(), &right);
}

TEST(TTreeTable, Can_Create_Tree_Table)
{
    ASSERT_NO_THROW(TTreeTable tree_t);
}

TEST(TTreeTable, Can_Insert_Record_Into_Tree_Table)
{
    TTreeTable tree_t;

    ASSERT_NO_THROW(tree_t.InsRecord("Ivanov I.I.", nullptr));
}

TEST(TTreeTable, Throws_While_Inserting_Record_With_Already_Existing_Key)
{
    TTreeTable tree_t;

    tree_t.InsRecord("Ivanov I.I.", nullptr);
    tree_t.InsRecord("Petrov P.P.", nullptr);
    tree_t.InsRecord("Abramov A.A.", nullptr);

    ASSERT_THROW(tree_t.InsRecord("Ivanov I.I.", nullptr), std::runtime_error);
}

TEST(TTreeTable, Can_Find_A_Record_In_Tree_Table)
{
    TTreeTable tree_t;

    tree_t.InsRecord("Ivanov I.I.", nullptr);

    ASSERT_NO_THROW(tree_t.FindRecord("Ivanov I.I."));
}

TEST(TTreeTable, Throws_While_Searching_For_A_Record_In_Empty_Tree_Table)
{
    TTreeTable tree_t;

    ASSERT_THROW(tree_t.FindRecord("key"), std::runtime_error);
}

TEST(TTreeTable, Throws_While_Searching_For_A_Record_With_Nonexistent_Key)
{
    TTreeTable tree_t;

    tree_t.InsRecord("Ivanov I.I.", nullptr);

    ASSERT_THROW(tree_t.FindRecord("key"), std::runtime_error);
}

TEST(TTreeTable, Can_Determine_Empty_Tree_Table)
{
    TTreeTable tree_t;

    EXPECT_TRUE(tree_t.IsEmpty());
}

TEST(TTreeTable, Throws_While_Removing_A_Record_With_Nonexistent_Key)
{
    TTreeTable tree_t;

    tree_t.InsRecord("Ivanov I.I.", nullptr);

    ASSERT_THROW(tree_t.DelRecord("Petrov P.P."), std::runtime_error);
}

TEST(TTreeTable, Throws_While_Removing_A_Record_From_Empty_Tree_Table)
{
    TTreeTable tree_t;

    ASSERT_THROW(tree_t.DelRecord("key"), std::runtime_error);
}

TEST(TTreeTable, Tree_Table_Becomes_Empty_After_Removing_All_Records)
{
    TTreeTable tree_t;
    tree_t.InsRecord("Petrov P.P.", nullptr);
    tree_t.InsRecord("Ivanov I.I.", nullptr);
    tree_t.InsRecord("Abramov A.A.", nullptr);
    tree_t.InsRecord("Dvorov D.D.", nullptr);

    tree_t.DelRecord("Petrov P.P.");
    tree_t.DelRecord("Ivanov I.I.");
    tree_t.DelRecord("Abramov A.A.");
    tree_t.DelRecord("Dvorov D.D.");

    EXPECT_TRUE(tree_t.IsEmpty());
}

TEST(TTreeTable,
Removing_A_Record_With_Random_Key_Does_Not_Break_Table_Sorted_State)
{
    TTreeTable tree_t;
    tree_t.InsRecord("Petrov P.P.", nullptr);
    tree_t.InsRecord("Ivanov I.I.", nullptr);
    tree_t.InsRecord("Abramov A.A.", nullptr);
    tree_t.InsRecord("Dvorov D.D.", nullptr);

    tree_t.DelRecord("Dvorov D.D.");

    tree_t.Reset();
    EXPECT_EQ(tree_t.GetKey(), "Abramov A.A.");
    tree_t.GoNext();
    EXPECT_EQ(tree_t.GetKey(), "Ivanov I.I.");
    tree_t.GoNext();
    EXPECT_EQ(tree_t.GetKey(), "Petrov P.P.");
}

TEST(TTreeTable,
Removing_A_Record_With_The_Least_Key_Does_Not_Break_Table_Sorted_State)
{
    TTreeTable tree_t;
    tree_t.InsRecord("Petrov P.P.", nullptr);
    tree_t.InsRecord("Ivanov I.I.", nullptr);
    tree_t.InsRecord("Abramov A.A.", nullptr);
    tree_t.InsRecord("Dvorov D.D.", nullptr);

    tree_t.DelRecord("Abramov A.A.");

    tree_t.Reset();
    EXPECT_EQ(tree_t.GetKey(), "Dvorov D.D.");
    tree_t.GoNext();
    EXPECT_EQ(tree_t.GetKey(), "Ivanov I.I.");
    tree_t.GoNext();
    EXPECT_EQ(tree_t.GetKey(), "Petrov P.P.");
}

TEST(TTreeTable,
Removing_A_Record_With_The_Greatest_Key_Does_Not_Break_Table_Sorted_State)
{
    TTreeTable tree_t;
    tree_t.InsRecord("Petrov P.P.", nullptr);
    tree_t.InsRecord("Ivanov I.I.", nullptr);
    tree_t.InsRecord("Abramov A.A.", nullptr);
    tree_t.InsRecord("Dvorov D.D.", nullptr);

    tree_t.DelRecord("Petrov P.P.");

    tree_t.Reset();
    EXPECT_EQ(tree_t.GetKey(), "Abramov A.A.");
    tree_t.GoNext();
    EXPECT_EQ(tree_t.GetKey(), "Dvorov D.D.");
    tree_t.GoNext();
    EXPECT_EQ(tree_t.GetKey(), "Ivanov I.I.");
}

TEST(TBalanceNode, Can_Create_Balance_Node)
{
    ASSERT_NO_THROW(TBalanceNode bn);
}

TEST(TBalanceNode, Can_Get_Balance_From_Balance_Node)
{
    TBalanceNode bn;

    EXPECT_EQ(bn.GetBalance(), BalOk);
}

TEST(TBalanceNode, Can_Set_Appropriate_Balance_Value)
{
    TBalanceNode bn;

    ASSERT_NO_THROW(bn.SetBalance(BalRight));
    EXPECT_EQ(bn.GetBalance(), BalRight);
}

TEST(TBalanceNode, Throws_While_Setting_Unsupported_Balance_Value)
{
    TBalanceNode bn;

    ASSERT_THROW(bn.SetBalance(10), std::invalid_argument);
}

TEST(TBalanceTree, Can_Create_Balance_Tree)
{
    ASSERT_NO_THROW(TBalanceTree bt);
}

TEST(TBalanceTree, Can_Insert_Record_Into_Balance_Tree)
{
    TBalanceTree bt;

    ASSERT_NO_THROW(bt.InsRecord("Ivanov I.I.", nullptr));
}

TEST(TBalanceTree, Throws_While_Inserting_Record_With_Already_Existing_Key)
{
    TBalanceTree bt;

    bt.InsRecord("Ivanov I.I.", nullptr);
    bt.InsRecord("Petrov P.P.", nullptr);
    bt.InsRecord("Abramov A.A.", nullptr);

    ASSERT_THROW(bt.InsRecord("Ivanov I.I.", nullptr), std::runtime_error);
}

TEST(TBalanceTree, Can_Find_A_Record_In_Balance_Tree)
{
    TBalanceTree bt;

    bt.InsRecord("Ivanov I.I.", nullptr);

    ASSERT_NO_THROW(bt.FindRecord("Ivanov I.I."));
}

TEST(TBalanceTree, Throws_While_Searching_For_A_Record_In_Empty_Balance_Tree)
{
    TBalanceTree bt;

    ASSERT_THROW(bt.FindRecord("key"), std::runtime_error);
}

TEST(TBalanceTree, Throws_While_Searching_For_A_Record_With_Nonexistent_Key)
{
    TBalanceTree bt;

    bt.InsRecord("Ivanov I.I.", nullptr);

    ASSERT_THROW(bt.FindRecord("key"), std::runtime_error);
}

TEST(TBalanceTree, Can_Determine_Empty_Balance_Tree)
{
    TBalanceTree bt;

    EXPECT_TRUE(bt.IsEmpty());
}

TEST(TBalanceTree, Throws_While_Removing_A_Record_From_Empty_Balance_Tree)
{
    TBalanceTree bt;

    ASSERT_THROW(bt.DelRecord("Key"), std::runtime_error);
}

TEST(TBalanceTree, Throws_While_Removing_A_Record_With_Nonexistent_Key)
{
    TBalanceTree bt;

    bt.InsRecord("Petrov P.P.", nullptr);
    bt.InsRecord("Ivanov I.I.", nullptr);
    bt.InsRecord("Abramov A.A.", nullptr);
    bt.InsRecord("Dvorov D.D.", nullptr);

    ASSERT_THROW(bt.DelRecord("Key"), std::runtime_error);
}

TEST(TBalanceTree, Can_Remove_A_Record_From_Balance_Tree)
{
    TBalanceTree bt;

    bt.InsRecord("Ivanov I.I.", nullptr);

    ASSERT_NO_THROW(bt.DelRecord("Ivanov I.I."));
    EXPECT_EQ(bt.GetDataCount(), 0);
}

TEST(TBalanceTree, Balance_Tree_Becomes_Empty_After_Removing_All_Records)
{
    TBalanceTree bt;
    bt.InsRecord("Petrov P.P.", nullptr);
    bt.InsRecord("Ivanov I.I.", nullptr);
    bt.InsRecord("Abramov A.A.", nullptr);
    bt.InsRecord("Dvorov D.D.", nullptr);

    bt.DelRecord("Petrov P.P.");
    bt.DelRecord("Ivanov I.I.");
    bt.DelRecord("Abramov A.A.");
    bt.DelRecord("Dvorov D.D.");

    EXPECT_TRUE(bt.IsEmpty());
}

TEST(TBalanceTree,
Removing_A_Record_With_Random_Key_Does_Not_Break_Table_Sorted_State)
{
    TBalanceTree bt;
    bt.InsRecord("Petrov P.P.", nullptr);
    bt.InsRecord("Ivanov I.I.", nullptr);
    bt.InsRecord("Abramov A.A.", nullptr);
    bt.InsRecord("Dvorov D.D.", nullptr);

    bt.DelRecord("Dvorov D.D.");

    bt.Reset();
    EXPECT_EQ(bt.GetKey(), "Abramov A.A.");
    bt.GoNext();
    EXPECT_EQ(bt.GetKey(), "Ivanov I.I.");
    bt.GoNext();
    EXPECT_EQ(bt.GetKey(), "Petrov P.P.");
}

TEST(TBalanceTree,
Removing_A_Record_With_The_Least_Key_Does_Not_Break_Table_Sorted_State)
{
    TBalanceTree bt;
    bt.InsRecord("Petrov P.P.", nullptr);
    bt.InsRecord("Ivanov I.I.", nullptr);
    bt.InsRecord("Abramov A.A.", nullptr);
    bt.InsRecord("Dvorov D.D.", nullptr);

    bt.DelRecord("Abramov A.A.");

    bt.Reset();
    EXPECT_EQ(bt.GetKey(), "Dvorov D.D.");
    bt.GoNext();
    EXPECT_EQ(bt.GetKey(), "Ivanov I.I.");
    bt.GoNext();
    EXPECT_EQ(bt.GetKey(), "Petrov P.P.");
}

TEST(TBalanceTree,
Removing_A_Record_With_The_Greatest_Key_Does_Not_Break_Table_Sorted_State)
{
    TBalanceTree bt;
    bt.InsRecord("Petrov P.P.", nullptr);
    bt.InsRecord("Ivanov I.I.", nullptr);
    bt.InsRecord("Abramov A.A.", nullptr);
    bt.InsRecord("Dvorov D.D.", nullptr);

    bt.DelRecord("Petrov P.P.");

    bt.Reset();
    EXPECT_EQ(bt.GetKey(), "Abramov A.A.");
    bt.GoNext();
    EXPECT_EQ(bt.GetKey(), "Dvorov D.D.");
    bt.GoNext();
    EXPECT_EQ(bt.GetKey(), "Ivanov I.I.");
}

//-----------------------------------------------------------------------------

//--------TESTING_TARRAYHASH--------

TEST(TArrayHash, Can_Create_Array_Hash_Table)
{
    ASSERT_NO_THROW(TArrayHash aht);
}

TEST(TArrayHash, Throws_While_Creating_Array_Hash_Table_With_Negative_Size)
{
    ASSERT_THROW(TArrayHash aht(-10), std::out_of_range);
}

TEST(TArrayHash, Throws_While_Creating_Array_Hash_Table_With_Too_Large_Size)
{
    ASSERT_THROW(TArrayHash aht(TabMaxSize + 10), std::out_of_range);
}

TEST(TArrayHash, Can_Find_A_Record_In_Array_Hash_Table)
{
    TArrayHash aht;

    aht.InsRecord("Key1", nullptr);
    aht.InsRecord("Key2", nullptr);
    aht.InsRecord("Key3", nullptr);

    ASSERT_NO_THROW(aht.FindRecord("Key2"));
}

TEST(TArrayHash,
Throws_While_Searching_For_A_Record_In_An_Empty_Array_Hash_Table)
{
    TArrayHash aht;

    ASSERT_THROW(aht.FindRecord("Key"), std::runtime_error);
}

TEST(TArrayHash, Throws_While_Searching_For_A_Record_With_Nonexistent_Key)
{
    TArrayHash aht;

    aht.InsRecord("Key1", nullptr);
    aht.InsRecord("Key2", nullptr);
    aht.InsRecord("Key3", nullptr);

    ASSERT_THROW(aht.FindRecord("Key4"), std::runtime_error);
}

TEST(TArrayHash, Can_Remove_Record_From_Array_Hash_Table)
{
    TArrayHash aht;

    aht.InsRecord("Key1", nullptr);

    ASSERT_NO_THROW(aht.DelRecord("Key1"));
}

TEST(TArrayHash, Table_Becomes_Empty_After_Removing_All_Records)
{
    TArrayHash aht;
    aht.InsRecord("Key1", nullptr);
    aht.InsRecord("Key2", nullptr);
    aht.InsRecord("Key3", nullptr);

    aht.DelRecord("Key1");
    aht.DelRecord("Key2");
    aht.DelRecord("Key3");

    EXPECT_TRUE(aht.IsEmpty());
}

TEST(TListHash, Can_Create_List_Hash_Table)
{
    ASSERT_NO_THROW(TListHash lht);
}

TEST(TListHash, Throws_While_Creating_List_Hash_Table_With_Negative_Size)
{
    ASSERT_THROW(TListHash lht(-10), std::out_of_range);
}

TEST(TListHash, Throws_While_Creating_List_Hash_Table_With_Too_Large_Size)
{
    ASSERT_THROW(TListHash lht(TabMaxSize + 10), std::out_of_range);
}

TEST(TListHash, Can_Insert_Record_Into_List_Hash_Table)
{
    TListHash lht;

    ASSERT_NO_THROW(lht.InsRecord("Key", nullptr));
}

TEST(TListHash, Throws_While_Inserting_A_Record_With_Already_Existing_Key)
{
    TListHash lht;

    lht.InsRecord("Key", nullptr);

    ASSERT_THROW(lht.InsRecord("Key", nullptr), std::runtime_error);
}

TEST(TListHash, Can_Find_A_Record_In_The_List_Hash_Table)
{
    TListHash lht;

    lht.InsRecord("Key1", nullptr);
    lht.InsRecord("Key2", nullptr);
    lht.InsRecord("Key3", nullptr);

    ASSERT_NO_THROW(lht.FindRecord("Key1"));
}

TEST(TListHash, Can_Remove_A_Record_From_List_Hash_Table)
{
    TListHash lht;

    lht.InsRecord("Key1", nullptr);
    lht.InsRecord("Key2", nullptr);
    lht.InsRecord("Key3", nullptr);

    ASSERT_NO_THROW(lht.DelRecord("Key2"));
}

TEST(TListHash, Throws_While_Removing_A_Record_From_Empty_List_Hash_Table)
{
    TListHash lht;

    ASSERT_THROW(lht.DelRecord("Key"), std::runtime_error);
}

TEST(TListHash, Throws_While_Removing_A_Record_With_Nonexistent_Key)
{
    TListHash lht;

    lht.InsRecord("Key1", nullptr);
    lht.InsRecord("Key2", nullptr);
    lht.InsRecord("Key3", nullptr);

    ASSERT_THROW(lht.DelRecord("Key4"), std::runtime_error);
}