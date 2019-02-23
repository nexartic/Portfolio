#include"tformula.h"
#include"MyStack.h"
#include<algorithm>
#include<cstring>
#include"tstack.h"
TFormula::TFormula(char* form)
{
	sizeFormula = strlen(form);
	copy(form, form + sizeFormula, Formula);
}
int TFormula::FormulaChecker(int Brackets[],int size)
{
	TStack stack(size);
	int countError = 0;
	int j = 0;
	for (unsigned i = 0; i < sizeFormula; i++)
	{
		if (Formula[i] == '(')
			stack.Put(i + 1);
		if (Formula[i] == ')')
		{
			if (stack.IsEmpty())
			{
				stack.Put(0);
				countError++;
				continue;
			}
			Brackets[j] = stack.Get();
			Brackets[j + 1] = i;
			j += 2;
		}
	}
	if (!stack.IsEmpty())
	{
		for (int i = 0; i < stack.GetDataCount(); i++)
		{
			Brackets[j] = stack.Get();
			Brackets[j + 1] = 0;
			countError++;
		}
	}
		return countError;
}
int TFormula::ColculatePriority(char symbol)
{
	switch (symbol)
	{
	case '(':
		return 0;
	case ')':
		return 1;
	case '+':
	case '-':
		return 2;
	case '*':
	case '/':
		return 3;
	default :
		return -1;
	}
}
int TFormula::FormulaConverter()
{
	int j = 0;
	MyStack<char> *stack = new MyStack<char>(sizeFormula);
	for (int i = 0; i < sizeFormula; i++)
	{
		if (Formula[i] >= '0' && Formula[i] <= '9')
		{
			PostfixForm[j++] = Formula[i];
		}
		int priority = ColculatePriority(Formula[i]);
		if (priority != -1)
		{
			if (priority == 1)
			{
				char buf = stack->Get();
				while (1)
				{
					if (ColculatePriority(buf) == 0)
						break;
					PostfixForm[j++] = buf;
					if(!stack->IsEmpty())
						buf = stack->Get();
					else
						break;
				}
			}
			if (priority == 0 || stack->IsEmpty())
			{
				stack->Put(Formula[i]);
				continue;
			}
			char buf = stack->Get();
			stack->Put(buf);
			if (priority > ColculatePriority(buf))
				stack->Put(Formula[i]);
			else
			{				
			  char buf = stack->Get();
			  while (priority <= ColculatePriority(buf))
			  {
				  PostfixForm[j++] = buf;
				  if(!stack->IsEmpty())
					  buf = stack->Get();
				  else
					  break;
			  }
			  stack->Put(Formula[i]);
			}
		}
	}

	while (1)
	{
		if (stack->IsEmpty())
			break;
		PostfixForm[j++] = stack->Get();
	}
	sizeFormula = j-1;
	return 1;
}
double TFormula::FormulaCalculator()
{
	MyStack<double> *stack = new MyStack<double>(sizeFormula);
	for (int i = 0; i < sizeFormula; i++)
	{
		if (PostfixForm[i] >= '0' && PostfixForm[i] <= '9')
		{
			double res = PostfixForm[i] - '0';
			stack->Put(res);
			continue;
		}
		double var1,var2,result;
		var1 = stack->Get();
		var2 = stack->Get();
		if (PostfixForm[i] == '+')
			result = var2 + var1;
		if (PostfixForm[i] == '-')
			result = var2 - var1;
		if (PostfixForm[i] == '*')
			result = var2 * var1;
		if (PostfixForm[i] == '/')
			result = var2 / var1;
		stack->Put(result);
	}
	return stack->Get();
}