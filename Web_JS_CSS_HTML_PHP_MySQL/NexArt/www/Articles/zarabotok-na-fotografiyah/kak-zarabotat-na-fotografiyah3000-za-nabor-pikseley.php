<!DOCTYPE html>
<?php
      $title = "Как заработать деньги на фотографиях.3000$ за набор пикселей|nexart";
      $discription = "Узнай как заработать деньги на фотографиях. Как рекламировать свои снимки и добиться лидирующих позиций. Заходи, даже если нет фотоаппарата";  
      $keywords = " заработать фотографии снимки фото изображения фотосток";
      $main_select = "false";
      $reg_select = "false";
      $path_AllArticles = "/index.php";
      $root = $_SERVER['DOCUMENT_ROOT'];
      require_once($root."/PHP/Header_up.php");
      require_once($root."/PHP/Link.php");
      require_once($root."/PHP/Header_bottom.php");
    ?>
        <?php 
            $h1 = "Как заработать деньги на фотографиях.3000$ за набор пикселей";
            $background_image = "/Articles/zarabotok-na-fotografiyah/img/photostock.jpg";
            $meta_width = "1400";
            $meta_height = "400";
            $alt = "Как заработать деньги на фотографиях";
            $border_bottom = "linear-gradient(to right, #444e37 5%, #273842 50%, #444e37 80%);";
            require_once($root."/PHP/ArticleHeader.php")
        ?>
		<div class="articles" itemscope itemtype="http://schema.org/Article" class="articles">
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
		     <li><i data-open='1' class='fa fa-circle' aria-hidden='true'></i><a href='#1'>Открыть свою студию или заработать на Фотобанках</a></li>
			 <li><i data-open='1' class='fa fa-circle' aria-hidden='true'></i><a href='#2'>С чего начать</a></li>
			 <li><i data-open='1' class='fa fa-caret-right aria-hidden='true'></i><a href='#3'>Трудности, с которыми вы столкнетесь</a>
			     <ul>
				     <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#3.1'>Инспекторы</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#3.2'>Легальность снимка</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#3.3'>Юридические аспекты</a></li>
				  </ul>
			 </li>
			  <li><i data-open='1' class='fa fa-caret-right aria-hidden='true'></i><a href='#4'>Причины отказа инспекторов. Каким должны быть фотографии</a>
			     <ul>
				     <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#4.1'>Первое и основное</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#4.2'>Актуальность снимка</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#4.3'>Логотип</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#4.4'>Бренд</a></li>
				  </ul>
			 </li>
			 <li><i data-open='1' class='fa fa-circle' aria-hidden='true'></i><a href='#5'>Виды лицензий</a>
			 </li>
			 <li><i data-open='1' class='fa fa-circle' aria-hidden='true'></i><a href='#6'>Как рекламировать фото</a>
			 </li>
			 <li><i data-open='1' class='fa fa-circle' aria-hidden='true'></i><a href='#7'>Плюсы и минусы</a></li>
		  </ul>
	   ";
	   require_once($root."/PHP/Footer.php");
	   require_once($root."/PHP/Footer_bottom.php");
       require_once($root."/PHP/Scripts.php");
	?>
	</body>
</html>