<!DOCTYPE html>
<?php
      $title = "Заработок в интернете на файлообменниках. Топ 5 файлообменников для заработка|nexart";
      $discription = "1500$ в месяц.Столько в среднем зарабатывают в интернете на файлообменниках. Каждый считал это лохтроном.Заходи и узнаешь почему их мнение изменилось";
      $keywords = "заработок файлообменник файл заработать сайт";
      $main_select = "false";
      $reg_select = "false";
      $path_AllArticles = "/index.php";
      $root = $_SERVER['DOCUMENT_ROOT'];
      require_once($root."/PHP/Header_up.php");
      require_once($root."/PHP/Link.php");
      require_once($root."/PHP/Header_bottom.php");
    ?>
        <?php 
            $h1 = "Заработок в интернете на файлообменниках. Топ 5 файлообменников для заработка";
            $background_image = "/Articles/zarabotok-na-fayloobmennikah/img/zarabotok_na-fayloobmennikah.jpg";
            $meta_width = "1400";
            $meta_height = "400";
            $alt = "Заработок в интернете на файлообменниках";
            $border_bottom = "linear-gradient(to right, #9299a9 5%, #e09f00 50%, #9299a9 80%);";
            require_once($root."/PHP/ArticleHeader.php")
        ?>
		<div itemscope itemtype="http://schema.org/Article" class="articles">
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
		     <li><i data-open='1' class='fa fa-circle' aria-hidden='true'></i><a href='#1'>Преимущество файлообменников перед торент - трекерами</a></li>
			 <li><i data-open='1' class='fa fa-circle' aria-hidden='true'></i><a href='#2'>Коротко о заработке на файлах</a></li>
			 <li><i data-open='1' class='fa fa-circle' aria-hidden='true'></i><a href='#3'>Какой контент интересен пользователям и где его брать ?</a>
			 </li>
			  <li><i data-open='1' class='fa fa-circle' aria-hidden='true'></i><a href='#4'>Какие файлообменники выбрать</a>
			 </li>
			 <li><i data-open='1' class='fa fa-circle' aria-hidden='true'></i><a href='#5'>На каких сайтах размещать ссылки</a>
			 </li>
			 <li><i data-open='1' class='fa fa-circle' aria-hidden='true'></i><a href='#6'>Что такое пост и как его оптимизировать</a>
			 </li>
			 <li><i data-open='1' class='fa fa-circle' aria-hidden='true'></i><a href='#7'>План действий</a></li>
		  </ul>
	   ";
	   require_once($root."/PHP/Footer.php");
	   require_once($root."/PHP/Footer_bottom.php");
       require_once($root."/PHP/Scripts.php");
	?>
	</body>
</html>