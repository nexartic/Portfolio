<!DOCTYPE html>
<?php
      $title = "Приемы для увеличения дополнительных продаж. Фишки менеджеров.|nexart";
      $discription = "Приемы и фишки, которые используют известные продавцы, соблазняя на дополнительные услуги. Креативные идеи увеличивающие продажи. Заходи, немедленно!";
      $keywords = "Приемы дополнительные прямые продажи фишки менеджер";
      $main_select = "false";
      $reg_select = "false";
      $path_AllArticles = "/index.php";
      $root = $_SERVER['DOCUMENT_ROOT'];
      require_once($root."/PHP/Header_up.php");
      require_once($root."/PHP/Link.php");
      require_once($root."/PHP/Header_bottom.php");
    ?>
        
        <?php 
            $h1 = "Приемы для увеличения дополнительных продаж. Фишки менеджеров.";
            $background_image = "/Articles/priemy-dlya-uvelicheniya-dopolnitelnyh-prodazh-fishki-menedzherov/img/job-seeker.jpg";
            $meta_width = "1400";
            $meta_height = "400";
            $alt = "Менеджеры по продажам сидят и готовятся к проведению встречи";
            $border_bottom = "linear-gradient(to right, #ffb51e 5%, #0f1626 32%, #d4d9df 99%);";
            require_once($root."/PHP/ArticleHeader.php")
        ?>
		<div class="articles" itemscope itemtype="http://schema.org/Article" class="articles">
			<?php require_once("Text.php")?>
			<?php require_once($root."/PHP/Call to action.php")?>
			<?php
	              $datePublished = "2019-02-21";
	              require_once($root."/PHP/ArticleInfo.php")
			?>
		</div>
	<?php
       $root = $_SERVER['DOCUMENT_ROOT'];
	   $content = "
	      <ul>
		     <li><i data-open='1' class='fa fa-circle' aria-hidden='true'></i><a href='#1'>Чего делать нельзя</a>
			 </li>
			<li><i data-open='1' class='fa fa-circle' aria-hidden='true'></i><a href='#2'>До какого момента предлагать товар?</a>
			 </li>
			 <li><i data-open='1' class='fa fa-circle' aria-hidden='true'></i><a href='#3'>Как завершать продажу</a>
			 </li>
			 <li><i data-open='1' class='fa fa-circle' aria-hidden='true'></i><a href='#4'>В какой момент предлагать доп. товар</a>
			 </li>
			 <li><i data-open='1' class='fa fa-circle' aria-hidden='true'></i><a href='#5'>Пробное завершение</a>
			 </li>
			 <li><i data-open='1' class='fa fa-circle' aria-hidden='true'></i><a href='#6'>История</a>
			 </li>
		  </ul>
	   ";
	   require_once($root."/PHP/Footer.php");
	   require_once($root."/PHP/Footer_bottom.php");
       require_once($root."/PHP/Scripts.php");
	?>
	</body>
</html>