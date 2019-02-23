<!DOCTYPE html>
<?php
      $title = "Меры по увеличению продаж. 22 совета из реальной практики.|nexart";
      $discription = "Какие меры по увеличннию своих продаж используют реальные бизнесмены и компании. 22 хитрости, которые помогли увеличить объем продаж. Заходи, если хочешь узнать реальные истории, а не теорию.";
      $keywords = "Меры увеличение объемов продаж фишки примеры";
      $main_select = "false";
      $reg_select = "false";
      $path_AllArticles = "/index.php";
      $root = $_SERVER['DOCUMENT_ROOT'];
      require_once($root."/PHP/Header_up.php");
      require_once($root."/PHP/Link.php");
      require_once($root."/PHP/Header_bottom.php");
    ?>
        
        <?php 
            $h1 = "Меры по увеличению продаж. 22 совета из реальной практики.";
            $background_image = "/Articles/mery-po-uvelicheniyu-prodazh/img/uvelichenie-rentabilnosti-prodazh.jpg";
            $meta_width = "1400";
            $meta_height = "400";
            $alt = "B2B компания обсуждает способы по увеличению показателей продаж";
            $border_bottom = "linear-gradient(to right, #f5d532 15%, #e36a1b 52%, #ae6a2d 80%);";
            require_once($root."/PHP/ArticleHeader.php")
        ?>
		<div class="articles" itemscope itemtype="http://schema.org/Article" class="articles">
			<?php require_once("Text.php")?>
			<?php require_once($root."/PHP/Call to action.php")?>
			<?php
	              $datePublished = "2018-12-21";
	              require_once($root."/PHP/ArticleInfo.php")
			?>
		</div>
	<?php
       $root = $_SERVER['DOCUMENT_ROOT'];
	   $content = "
	      <ul>
		     <li><i data-open='1' class='fa fa-caret-right' aria-hidden='true'></i><a href='#1'>Марк Уэйшек</a>
			     <ul>
				     <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#1.1'>Как развить ценность товара</a></li>
				  </ul>
			 </li>
			 <li><i data-open='1' class='fa fa-caret-right' aria-hidden='true'></i><a href='#2'>Джули Хансен</a>
			     <ul>
				     <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#2.1'>4 типа клиентов, и как с ними работать</a></li>
				  </ul>
			 </li>
			 <li><i data-open='1' class='fa fa-caret-right' aria-hidden='true'></i><a href='#3'>Джефф Шор</a>
			     <ul>
				     <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#3.1'>5 приемов, которые больше не работают и от которых нужно отказаться</a></li>
				  </ul>
			 </li>
			 <li><i data-open='1' class='fa fa-caret-right' aria-hidden='true'></i><a href='#4'>Джил Конрат</a>
			    <ul>
			     <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#4.1'>Как найти новых клиентов</a></li>
				 </ul>
			 </li>
			 <li><i data-open='1' class='fa fa-caret-right' aria-hidden='true'></i><a href='#5'>Майкл Шульц</a>
			      <ul>
			     <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#5.1'>12 вопросов, которые усилят боль покупателей</a></li>
				 </ul>
			 </li>
			 <li><i data-open='1' class='fa fa-caret-right' aria-hidden='true'></i><a href='#6'>Джилл Харрингтон</a>
			       <ul>
			     <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#6.1'>Что можно узнать, если выслушать покупателя.</a></li>
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