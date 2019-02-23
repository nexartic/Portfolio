<!DOCTYPE html>
<?php
      $title = "Заработок в инстаграм на лайках и подписках. Сколько реально можно заработать|nexart";
      $discription = "В данной статье ты узнаешь все способы заработка в инстаграм.На лайках и подписках.На продаже фото.И даже на партнерских программах.Заходи.";
      $keywords = "Заработок инстаграм лайках подписках фото соцсеть";
      $main_select = "false";
      $reg_select = "false";
      $path_AllArticles = "/index.php";
      $root = $_SERVER['DOCUMENT_ROOT'];
      require_once($root."/PHP/Header_up.php");
      require_once($root."/PHP/Link.php");
      require_once($root."/PHP/Header_bottom.php");
    ?>
         <?php 
            $h1 = "Заработок в инстаграм на лайках и подписках. Сколько реально можно заработать";
            $background_image = "/Articles/zarabotok-v-instagram/img/instagram_zarabotok.jpg";
            $meta_width = "1400";
            $meta_height = "400";
            $alt = "Заработок в инстаграм на лайках";
            $border_bottom = "linear-gradient(to right, #ad2ba2 10%, #f82a4e 60%, #f8bc35 80%);";
            require_once($root."/PHP/ArticleHeader.php")
        ?>
		<div itemscope itemtype="http://schema.org/Article"  class="articles">
			<?php require_once("Text.php")?>
			<?php require_once($root."/PHP/Call to action.php")?>
			<?php
	              $datePublished = "2018-12-3";
	              require_once($root."/PHP/ArticleInfo.php")
			?>
		</div>
	<?php
       $root = $_SERVER['DOCUMENT_ROOT'];
	   $content = "
	      <ul>
			 <li><i data-open='1' class='fa fa-caret-right' aria-hidden='true'></i><a href='#1'>С чего начать свое продвижение в Инстаграм</a>
			     <ul>
				     <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#1.1'>О заработке в инстаграм на лайках и подписках</a></li>
					 <li><i data-open='1' class='fa fa-caret-right' aria-hidden='true'></i><a href='#1.2'>Методы наращивания подписчиков</a>
					      <ul>
							 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#1.2.1'>Как правильно оформить свой аккаунт</a></li>
							 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#1.2.2'>Зачем отвечать на комментарии</a>
							 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#1.2.3'>Используйте остроумные хештеги</a></li>
							 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#1.2.4'>Зачем нужен видео-контент</a>
							 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#1.2.5'>Воспользуйтесь помощью со стороны</a></li>
							 </li>
						  </ul>
					 </li>
				  </ul>
			 </li>
			 <li><i data-open='1' class='fa fa-caret-right' aria-hidden='true'></i><a href='#2'>Способы заработка в Инстаграм</a>
			       <ul>
				     <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#2.1'>Как продавать фотографий</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#2.2'>Что такое платный постинг</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#2.3'>Партнерский маркетинг</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#2.4'>Интернет магазин</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#2.5'>Платные консультации</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#2.6'>Инфобизнес</a></li>
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