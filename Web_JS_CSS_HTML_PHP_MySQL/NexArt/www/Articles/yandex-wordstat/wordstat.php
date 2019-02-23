<!DOCTYPE html>
<?php
      $title = "Яндекс Вордстат  статистика ключевых слов. Учимся читать мысли пользователей.";
      $discription = "Вы владелец сайта? Начинающий бизнесмен? Не важно. Яндекс Вордстат поможет вам в любом начинании. А я помогу освоить Вордстат.Скорей заходи";
      $keywords = "вордстат яндекс wordstat yandex поисковый запрос";
      $main_select = "false";
      $reg_select = "false";
      $path_AllArticles = "/index.php";
      $root = $_SERVER['DOCUMENT_ROOT'];
      require_once($root."/PHP/Header_up.php");
      require_once($root."/PHP/Link.php");
      require_once($root."/PHP/Header_bottom.php");
    ?>
        <?php 
            $h1 = "<span style='color:red;'>Я</span>ндекс Вордстат статистика ключевых слов. Учимся читать мысли пользователей.";
            $background_image = "/Articles/yandex-wordstat/img/yandex-wordstat.jpg";
            $meta_width = "1600";
            $meta_height = "487";
            $alt = "Яндекс Вордстат";
            $border_bottom = "linear-gradient(to right, #2e2e2e 5%, #795008 50%, #2e2e2e 80%);";
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
		     <li><i data-open='1' class='fa fa-circle' aria-hidden='true'></i><a href='#1'>Что такое Яндекс Вордстат в 3-х словах</a></li>
			 <li><i data-open='1' class='fa fa-caret-right' aria-hidden='true'></i><a href='#2'>Основной функционал</a>
			     <ul>
				     <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#2.1'>Левый столбец</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#2.2'>Правый столбец</a></li>
				  </ul>
			 </li>
			 <li><i data-open='1' class='fa fa-caret-right' aria-hidden='true'></i><a href='#3'>Расширенный функционал</a>
			       <ul>
				     <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#3.1'>Тип устройства</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#3.2'>Региональность</a></li>
					 <li><i data-open='1' class='fa fa-caret-right' aria-hidden='true'></i><a href='#3.3'>Вкладка 'По регионам'</a>
					    <ul>
							 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#3.3.1'>Региональная популярность</a></li>
							 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#3.3.2'>Карта</a></li>
				         </ul>
					 </li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#3.4'>История запросов</a></li>
				  </ul>
			 </li>
			 <li><i data-open='1' class='fa fa-caret-right' aria-hidden='true'></i><a href='#4'>Дополнения</a>
			     <ul>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#4.1'>Yandex Wordstat Helper</a></li>
				 </ul>
			 </li>
			 <li><i data-open='1' class='fa fa-circle' aria-hidden='true'></i><a href='#5'>Для чего нужен Вордстат</a></li>
		  </ul>
	   ";
	   require_once($root."/PHP/Footer.php");
	   require_once($root."/PHP/Footer_bottom.php");
       require_once($root."/PHP/Scripts.php");
	?>
	</body>
</html>