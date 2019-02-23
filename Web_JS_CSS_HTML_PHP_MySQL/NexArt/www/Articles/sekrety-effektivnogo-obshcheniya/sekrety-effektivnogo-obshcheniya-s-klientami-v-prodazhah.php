<!DOCTYPE html>
<?php
      $title = "Секреты эффективного общения с клиентами в продажах|nexart";
      $discription = "Узнайте все уловки эффективного общения, которые применяют лучшие продавцы, чтобы соблазнить нас на покупку их товара. Заходите, если хотите научиться использовать эти приемы, а не попадаться в них.";
      $keywords = "Общение клиенты продажы эффективно психология телефон";
      $main_select = "false";
      $reg_select = "false";
      $path_AllArticles = "/index.php";
      $root = $_SERVER['DOCUMENT_ROOT'];
      require_once($root."/PHP/Header_up.php");
      require_once($root."/PHP/Link.php");
      require_once($root."/PHP/Header_bottom.php");
    ?>
         <?php 
            $h1 = "Секреты эффективного общения с клиентами в продажах";
            $background_image = "/Articles/sekrety-effektivnogo-obshcheniya/img/pravilnoe_obchenie_s_klientami.jpg";
            $meta_width = "1400";
            $meta_height = "400";
            $alt = "Общение с клиентами. Как эффективно продавать. Психология общения";
            $border_bottom = "linear-gradient(to right, #d2ce58 10%, #393839 30%, #ac9a82 80%);";
            require_once($root."/PHP/ArticleHeader.php")
        ?>
		<div itemscope itemtype="http://schema.org/Article"  class="articles">
			<?php require_once("Text.php")?>
			<?php require_once($root."/PHP/Call to action.php")?>
			<?php
	              $datePublished = "2019-01-19";
	              require_once($root."/PHP/ArticleInfo.php")
			?>
		</div>
	<?php
       $root = $_SERVER['DOCUMENT_ROOT'];
	   $content = "
	      <ul>
			 <li><i data-open='1' class='fa fa-circle' aria-hidden='true'></i><a href='#1'>Новости и новинки</a>
			 </li>
			 <li><i data-open='1' class='fa fa-circle' aria-hidden='true'></i><a href='#2'>Поиграйте на желании сэкономить</a>
			 </li>
			 <li><i data-open='1' class='fa fa-circle' aria-hidden='true'></i><a href='#3'>Разогрейте интерес к вашей продукции заранее</a>
			 </li>
			 <li><i data-open='1' class='fa fa-circle' aria-hidden='true'></i><a href='#4'>Заставьте покупателя чувствовать себя обязанным</a>
			 </li>
			 <li><i data-open='1' class='fa fa-circle' aria-hidden='true'></i><a href='#5'>Фреймы из НЛП</a>
			 </li>
			 <li><i data-open='1' class='fa fa-circle' aria-hidden='true'></i><a href='#6'>Как войти в раппорт с клиентом</a>
			 </li>
			 <li><i data-open='1' class='fa fa-circle' aria-hidden='true'></i><a href='#7'>Не переходите на личности</a>
			 </li>
			 <li><i data-open='1' class='fa fa-circle' aria-hidden='true'></i><a href='#8'>Как выйти из конфликта</a>
			 </li>
		  </ul>
	   ";
	   require_once($root."/PHP/Footer.php");
	   require_once($root."/PHP/Footer_bottom.php");
       require_once($root."/PHP/Scripts.php");
	?>
	</body>
</html>