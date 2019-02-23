<!DOCTYPE html>
<?php
      $title = "200+ правильных вопросов, от которых взлетят ваши продажи|nexart";
      $discription = "Список из 200+ вопросов на любой случай жизни. Открытые, Альтернативные, Вопросы для выявления потребностей. Закрывающие вопросы, извлекающие и многие другие. Немедленно заходите. ";
      $keywords = "Правильные вопросы альтернативные открытые продажи список";
      $main_select = "false";
      $reg_select = "false";
      $path_AllArticles = "/index.php";
      $root = $_SERVER['DOCUMENT_ROOT'];
      require_once($root."/PHP/Header_up.php");
      require_once($root."/PHP/Link.php");
      require_once($root."/PHP/Header_bottom.php");
    ?>
         <?php 
            $h1 = "200+ правильных вопросов, от которых взлетят ваши продажи";
            $background_image = "/Articles/pravilnye-voprosy-pri-prodazhe/img/na_vzlet.jpg";
            $meta_width = "1400";
            $meta_height = "400";
            $alt = "Список из альтернативных, открывающих и закрывающих вопросов";
            $border_bottom = "linear-gradient(to right, #5f8c91 10%, #e21534 30%, #e5eedb 80%);";
            require_once($root."/PHP/ArticleHeader.php")
        ?>
		<div itemscope itemtype="http://schema.org/Article"  class="articles">
			<?php require_once("Text.php")?>
			<?php require_once($root."/PHP/Call to action.php")?>
			<?php
	              $datePublished = "2019-02-05";
	              require_once($root."/PHP/ArticleInfo.php")
			?>
		</div>
	<?php
       $root = $_SERVER['DOCUMENT_ROOT'];
	   $content = "
	      <ul>
			 <li><i data-open='1' class='fa fa-circle' aria-hidden='true'></i><a href='#1'>Общие, открывающие вопросы, ситуационные</a>
			 </li>
			 <li><i data-open='1' class='fa fa-circle' aria-hidden='true'></i><a href='#2'>Вопросы для установки раппорта с клиентом</a>
			 </li>
			 <li><i data-open='1' class='fa fa-circle' aria-hidden='true'></i><a href='#3'>Проблемные вопросы</a>
			 </li>
			 <li><i data-open='1' class='fa fa-circle' aria-hidden='true'></i><a href='#4'>Вопросы, позволяющие назвать / узнать допустимую цену</a>
			 </li>
			 <li><i data-open='1' class='fa fa-circle' aria-hidden='true'></i><a href='#5'>Вопросы, для выяснения лица, принимающего решения</a>
			 </li>
			 <li><i data-open='1' class='fa fa-circle' aria-hidden='true'></i><a href='#6'>Вопросы, которые заставляют клиента помечтать. Вопросы показывающие, как изменится жизнь клиента</a>
			 </li>
			 <li><i data-open='1' class='fa fa-circle' aria-hidden='true'></i><a href='#7'>Вопросы, для получения критериев оценивания(KPI)</a>
			 </li>
			 <li><i data-open='1' class='fa fa-circle' aria-hidden='true'></i><a href='#8'>Вопросы, выясняющие проблемы, которые могут появиться при дальнейшей работе</a>
			 </li>
			 <li><i data-open='1' class='fa fa-circle' aria-hidden='true'></i><a href='#9'>Вопросы, отвечающие на возражения клиентов</a>
			 </li>
			 <li><i data-open='1' class='fa fa-circle' aria-hidden='true'></i><a href='#10'>Закрывающие вопросы</a>
			 </li>
			 <li><i data-open='1' class='fa fa-circle' aria-hidden='true'></i><a href='#11'>Вопросы, помогающие найти новых клиентов</a>
			 </li>
		  </ul>
	   ";
	   require_once($root."/PHP/Footer.php");
	   require_once($root."/PHP/Footer_bottom.php");
       require_once($root."/PHP/Scripts.php");
	?>
	</body>
</html>