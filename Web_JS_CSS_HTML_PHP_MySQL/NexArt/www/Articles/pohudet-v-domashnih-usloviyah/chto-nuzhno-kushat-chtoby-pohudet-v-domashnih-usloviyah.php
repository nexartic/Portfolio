<!DOCTYPE html>
<?php
      $title = "Что нужно кушать чтобы похудеть в домашних условиях. 10 советов обжорам|nexart";
      $discription = "Желаешь узнать что нужно кушать чтобы похудеть в домашних условиях ? Для начала перестать много есть. Заходи, если хочешь узнать больше.";
      $keywords = "что нужно кушать похудеть домашних условиях";
      $main_select = "false";
      $reg_select = "false";
      $path_AllArticles = "/index.php";
      $root = $_SERVER['DOCUMENT_ROOT'];
      require_once($root."/PHP/Header_up.php");
      require_once($root."/PHP/Link.php");
      require_once($root."/PHP/Header_bottom.php");
    ?>
         <?php 
            $h1 = "Что нужно кушать чтобы похудеть в домашних условиях. 10 советов обжорам";
            $background_image = "/Articles/pohudet-v-domashnih-usloviyah/img/kak-pohudet.jpg";
            $meta_width = "1400";
            $meta_height = "400";
            $alt = "Как похудеть в домашних условиях";
            $border_bottom = "linear-gradient(to right, #ffffff 5%, #d49b79 40%, #273246 70%);";
            require_once($root."/PHP/ArticleHeader.php")
        ?>
		<div class="articles" itemscope itemtype="http://schema.org/Article" class="articles">
			<?php require_once("Text.php")?>
			<?php require_once($root."/PHP/Call to action.php")?>
			<?php
	              $datePublished = "2018-11-26";
	              require_once($root."/PHP/ArticleInfo.php")
			?>
		</div>
	<?php
       $root = $_SERVER['DOCUMENT_ROOT'];
	   $content = "
	      <ul>
		     <li><i data-open='1' class='fa fa-caret-right' aria-hidden='true'></i><a href='#0'>Диеты для похудения</a>
			      <ul>
				     <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#1'>Ананасовая</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#2'>Арбузная</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#3'>Артишековая</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#4'>Дюкан</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#5'>Аткинс</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#6'>13 дней</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#7'>Scaredale</a></li>
					  <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#8'>Перрикоун 28 дней</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#9'>Палео</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#10'>Макробиотическая</a></li>
				  </ul>
			 </li>
			 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#11'>Итог</a>
		  </ul>
	   ";
	   require_once($root."/PHP/Footer.php");
	   require_once($root."/PHP/Footer_bottom.php");
       require_once($root."/PHP/Scripts.php");
	?>
	</body>
</html>