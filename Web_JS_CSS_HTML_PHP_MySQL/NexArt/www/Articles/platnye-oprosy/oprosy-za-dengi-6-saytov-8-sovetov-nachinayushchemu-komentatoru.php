<!DOCTYPE html>
<?php
      $title = "Платные опросы онлайн за деньги. 6 сайтов + 8 советов начинающему коментатору|nexart";
      $discription = "Всю жизнь мечтал проходить платные опросы онлайн за деньги ? Тогда ты выбрал правильный сайт. Заходи и узнаешь как можно зарабатывать сидя у телевизора";
      $keywords = "опросы деньги платные деньги компании заработать";
      $main_select = "false";
      $reg_select = "false";
      $path_AllArticles = "/index.php";
      $root = $_SERVER['DOCUMENT_ROOT'];
      require_once($root."/PHP/Header_up.php");
      require_once($root."/PHP/Link.php");
      require_once($root."/PHP/Header_bottom.php");
    ?>
        <?php 
            $h1 = "Платные опросы онлайн за деньги. 6 сайтов + 8 советов начинающему коментатору";
            $background_image = "/Articles/platnye-oprosy/img/platniy-oprosi.jpg";
            $meta_width = "1400";
            $meta_height = "400";
            $alt = "Платные опросы";
            $border_bottom = "linear-gradient(to right, #d4d4d4 10%, #151515 60%, #520203 80%);";
            require_once($root."/PHP/ArticleHeader.php")
        ?>
		<div class="articles" itemscope itemtype="http://schema.org/Article" class="articles">
			<?php require_once("Text.php")?>
			<?php require_once($root."/PHP/Call to action.php")?>
			<?php
	              $datePublished = "2018-11-19";
	              require_once($root."/PHP/ArticleInfo.php")
			?>
		</div>
	<?php
       $root = $_SERVER['DOCUMENT_ROOT'];
	   $content = "
	      <ul>
		     <li><i data-open='1' class='fa fa-caret-right' aria-hidden='true'></i><a href='#1'>6 самых прибыльных сайтов-опросников</a>
			      <ul>
				     <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#1.1'>MySurvey</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#1.2'>Centro de Opinion</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#1.3'>Opina</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#1.4'>Toluna</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#1.5'>Surveyeah</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#1.6'>Myiyo</a></li>
				  </ul>
			 </li>
			 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#2'>С чего начать</a></li>
			 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#3'>Как работают сайты опросники</a></li>
			 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#4'>Как заработать деньги с платными опросами</a></li>
			 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#5'>8 советов как правильно заполнять опросы</a></li>
		  </ul>
	   ";
	   require_once($root."/PHP/Footer.php");
	   require_once($root."/PHP/Footer_bottom.php");
       require_once($root."/PHP/Scripts.php");
	?>
	</body>
</html>