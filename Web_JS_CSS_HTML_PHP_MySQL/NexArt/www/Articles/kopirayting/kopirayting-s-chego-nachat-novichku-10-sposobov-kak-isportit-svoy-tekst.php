<!DOCTYPE html>
<?php
      $title = "Cоставление рекламных текстов. Копирайтинг. 10 способов как испортить свой текст|nexart";
      $discription = "Узнайте как составить рекламные тексты. Вы научитесь писать Seo статьи. Заходите и узнайте - почему биржи копирайтинга это зло";
      $keywords = "копирайтинг заработать текст продающий биржи рерайтинг";
      $main_select = "false";
      $reg_select = "false";
      $path_AllArticles = "/index.php";
      $root = $_SERVER['DOCUMENT_ROOT'];
      require_once($root."/PHP/Header_up.php");
      require_once($root."/PHP/Link.php");
      require_once($root."/PHP/Header_bottom.php");
    ?>
        <?php 
            $h1 = "Cоставление рекламных текстов. Копирайтинг. 10 способов как испортить свой текст.";
            $background_image = "/Articles/kopirayting/img/kopiraiting.jpg";
            $meta_width = "1400";
            $meta_height = "400";
            $alt = "Составление рекламных текстов";
            $border_bottom = "linear-gradient(to right, #cbc0c3 10%, #17272b 30%, #17272b 60%, #e5a701 100%);";
            require_once($root."/PHP/ArticleHeader.php")
        ?>
		<div itemscope itemtype="http://schema.org/Article"  class="articles">
			<?php require_once("Text.php")?>
			<?php require_once($root."/PHP/Call to action.php")?>
			<?php
	              $datePublished = "2018-10-28";
	              require_once($root."/PHP/ArticleInfo.php")
			?>
		</div>
	<?php
       $root = $_SERVER['DOCUMENT_ROOT'];
	   $content = "
	      <ul>
		     <li><i data-open='1' class='fa fa-caret-right' aria-hidden='true'></i><a href='#1'>Составление рекламного текста</a>
			      <ul>
				     <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#1.1'>Каким должно быть содержание</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#1.2'>Работа с возражениями</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#1.3'>Призыв</a></li>
				  </ul>
			 </li>
			 <li><i data-open='1' class='fa fa-caret-right' aria-hidden='true'></i><a href='#2'>Составление продающего текста</a>
			       <ul>
				     <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#2.1'>Что такое броский заголовок</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#2.2'>Идеальное содержание</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#2.3'>Заключение</a></li>
				  </ul>
			 </li>
			 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#3'>10 ошибок, которые вы допустите</a></li></li>
			 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#4'>Зачем лично тебе копирайтинг</a></li></li>
			 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#5'>SEO копирайтинг</a></li></li>
			 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#6'>Множественный источник дохода</a></li></li>
		  </ul>
	   ";
	   require_once($root."/PHP/Footer.php");
	   require_once($root."/PHP/Footer_bottom.php");
       require_once($root."/PHP/Scripts.php");
	?>
	</body>
</html>