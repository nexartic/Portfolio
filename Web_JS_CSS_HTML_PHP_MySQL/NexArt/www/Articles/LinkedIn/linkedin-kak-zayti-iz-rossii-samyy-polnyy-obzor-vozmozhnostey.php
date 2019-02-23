<!DOCTYPE html>
<?php
      $title = "LinkedIn. Как зайти в России + Самый полный обзор возможностей|nexart";
      $discription = "Как обойти блокировку ? Как создать страницу вашей компании ? Как искать работу в деловой социальной сети LinkedIn. Заходи, если хочешь узнать все про эту запрещенную социальную сеть.";
      $keywords = "LinkedIn обойти блокировку Россия обзор возможностей";
      $main_select = "false";
      $reg_select = "false";
      $path_AllArticles = "/index.php";
      $root = $_SERVER['DOCUMENT_ROOT'];
      require_once($root."/PHP/Header_up.php");
      require_once($root."/PHP/Link.php");
      require_once($root."/PHP/Header_bottom.php");
    ?>
         <?php 
            $h1 = "LinkedIn. Как зайти в России + Самый полный обзор возможностей";
            $background_image = "/Articles/LinkedIn/img/LinkedIn.jpg";
            $meta_width = "1400";
            $meta_height = "400";
            $alt = "LinkedIn - самая неизвестная социальная сеть в России";
            $border_bottom = "linear-gradient(to right, #131f37 20%, #416caa 60%, #6ea4d6 80%);";
            require_once($root."/PHP/ArticleHeader.php")
        ?>
		<div itemscope itemtype="http://schema.org/Article"  class="articles">
			<?php require_once("Text.php")?>
			<?php require_once($root."/PHP/Call to action.php")?>
			<?php
	              $datePublished = "2018-12-28";
	              require_once($root."/PHP/ArticleInfo.php")
			?>
		</div>
	<?php
       $root = $_SERVER['DOCUMENT_ROOT'];
	   $content = "
	      <ul>
			 <li><i data-open='1' class='fa fa-caret-right' aria-hidden='true'></i><a href='#1'>Способы обхода блокировки</a>
			     <ul>
				     <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#1.1'>Смена адреса</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#1.2'>Расширение для браузера</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#1.3'>Tor</a></li>
				  </ul>
			 </li>
			 <li><i data-open='1' class='fa fa-caret-right' aria-hidden='true'></i><a href='#2'>Основные возможности</a>
			       <ul>
				     <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#2.1'>Информация о просмотрах вашего профиля</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#2.2'>Поиск людей</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#2.3'>Преимущества премиум аккаунта</a>
					     <ul>
				            <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#2.3.1'>Пакет 'Бизнес'</a>
							<li><i class='fa fa-circle' aria-hidden='true'></i><a href='#2.3.2'>Пакет 'Продажи'</a> 
				         </ul>
					 </li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#2.4'>Страница компании</a></li>
				  </ul>
			 </li>
		  </ul>
	   ";
	   require_once($root."/PHP/Footer.php");
	   require_once($root."/PHP/Footer_bottom.php");
       require_once($root."/PHP/Scripts.php");
	?>
	</body>
</html>