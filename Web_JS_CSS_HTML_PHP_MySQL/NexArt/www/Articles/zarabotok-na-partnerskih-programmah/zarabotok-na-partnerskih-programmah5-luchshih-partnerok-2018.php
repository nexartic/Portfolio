<!DOCTYPE html>
<?php
      $title = "Обучение заработку на партнерских программах.5 лучших партнерок ".date('Y')."|nexart";
      $discription = "Хочешь обучиться заработку на партнерских программах? Заходи и узнаешь какая партнерская программа подойдет лично тебе. А также 8 способов как продвигать ее";
      $keywords = "партнерская программа заработать реферальная ссылка";
      $main_select = "false";
      $reg_select = "false";
      $path_AllArticles = "/index.php";
      $root = $_SERVER['DOCUMENT_ROOT'];
      require_once($root."/PHP/Header_up.php");
      require_once($root."/PHP/Link.php");
      require_once($root."/PHP/Header_bottom.php");
    ?>
        <?php 
            $h1 = "Обучение заработку на партнерских программах.5 лучших партнерок ".date('Y')."";
            $background_image = "/Articles/zarabotok-na-partnerskih-programmah/img/partner.jpg";
            $meta_width = "1400";
            $meta_height = "400";
            $alt = "Обучение заработку на партнерских программах";
            $border_bottom = "linear-gradient(to right, #74869c 5%, #a48280 30%, #0d1218 80%);";
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
			 <li><i data-open='1' class='fa fa-caret-right' aria-hidden='true'></i><a href='#1'>Как выбрать лучшую парнерку</a>
			     <ul>
				     <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#1.1'>Какую цену выбрать</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#1.2'>Наложенный платеж</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#1.3'>Готовая реклама</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#1.4'>Тематика</a></li>
				  </ul>
			 </li>
			 <li><i data-open='1' class='fa fa-caret-right' aria-hidden='true'></i><a href='#2'>Способы продвижения</a>
			       <ul>
				     <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#2.1'>Бесплатные</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#2.2'>Платные</a></li>
				  </ul>
			 </li>
			 <li><i data-open='1' class='fa fa-caret-right' aria-hidden='true'></i><a href='#3'>5 партнерских программ, проверенных временем</a>
			     <ul>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#3.1'>Kolorado.ru</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#3.2'>EPN.bz</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#3.3'>Vsemayki.ru</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#3.4'>Englishdom.com</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#3.5'>Photoshop-master.org</a></li>
				 </ul>
			 </li>
			 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#4'>Еще несколько интересных партнерок</a></li>
			  <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#5'>Как найти программу по интересующей вас тематике</a></li>
		  </ul>
	   ";
	   require_once($root."/PHP/Footer.php");
	   require_once($root."/PHP/Footer_bottom.php");
       require_once($root."/PHP/Scripts.php");
	?>
	</body>
</html>