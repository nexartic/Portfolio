<!DOCTYPE html>
<?php
      $title = "Как можно заработать на Авито в интернете. Строим свой первый товарный бизнес|nexart";
      $discription = "Хочешь начать зарабатывать на Авито в интернете? Открыть свой товарный бизнес и заработать на этом миллионы. Со вторым будет сложновато. А вот про товарный бизнес ты узнаешь. Чего же ты ждешь, кликай по ссылке.";
      $keywords = "как заработать авито объявление товар продукт";
      $main_select = "false";
      $reg_select = "false";
      $path_AllArticles = "/index.php";
      $root = $_SERVER['DOCUMENT_ROOT'];
      require_once($root."/PHP/Header_up.php");
      require_once($root."/PHP/Link.php");
      require_once($root."/PHP/Header_bottom.php");
    ?>
        
        <?php 
            $h1 = "Как можно заработать на Авито  в интернете. Строим свой первый товарный бизнес.";
            $background_image = "/Articles/avito/img/avito.png";
            $meta_width = "1474";
            $meta_height = "420";
            $alt = "Заработок на авито в интернете";
            $border_bottom = "linear-gradient(to right, #95cc26 25%, #00a8ff 52%, #fe6263 80%);";
            require_once($root."/PHP/ArticleHeader.php")
        ?>
		<div class="articles" itemscope itemtype="http://schema.org/Article" class="articles">
			<?php require_once("Text.php")?>
			<?php require_once($root."/PHP/Call to action.php")?>
			<?php
	              $datePublished = "2018-11-17";
	              require_once($root."/PHP/ArticleInfo.php")
			?>
		</div>
	<?php
       $root = $_SERVER['DOCUMENT_ROOT'];
	   $content = "
	      <ul>
		     <li><i data-open='1' class='fa fa-caret-right' aria-hidden='true'></i><a href='#1'>7 самых продаваемых товаров на Авито</a>
			      <ul>
				     <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#1.1'>То, что нужно девушкам</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#1.2'>Детская одежда</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#1.3'>Одежда для телефонов</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#1.4'>Какую обувь покупать</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#1.5'>Спортивные товары и допинг</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#1.6'>Лучший подарок</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#1.7'>Товары для животных</a></li>
				  </ul>
			 </li>
			 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#2'>Составление объявления и оптимизация</a></li>
			 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#3'>Где найти дешевые товары</a></li></li>
		  </ul>
	   ";
	   require_once($root."/PHP/Footer.php");
	   require_once($root."/PHP/Footer_bottom.php");
       require_once($root."/PHP/Scripts.php");
	?>
	</body>
</html>