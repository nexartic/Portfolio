<!DOCTYPE html>
<?php
      $title = "Методы холодных звонков. Как звонить, чтобы вам перезванивали.|nexart";
      $discription = "Хотите узнать какие методы холодных звонков существуют ? А также какие из них самые эффективные ? Заходите, если надоело слышать 'нет'";
      $keywords = "методы хлодных звонков скрипт продажа клиент";
      $main_select = "false";
      $reg_select = "false";
      $path_AllArticles = "/index.php";
      $root = $_SERVER['DOCUMENT_ROOT'];
      require_once($root."/PHP/Header_up.php");
      require_once($root."/PHP/Link.php");
      require_once($root."/PHP/Header_bottom.php");
    ?>
        <?php 
            $h1 = "Методы холодных звонков. Как звонить, чтобы вам перезванивали.";
            $background_image = "/Articles/metody-holodnyh-zvonkov/img/zvonok.jpg";
            $meta_width = "1400";
            $meta_height = "400";
            $alt = "Методы холодных звонков";
            $border_bottom = "linear-gradient(to right, #d4d4d4 10%, #151515 90%);";
            require_once($root."/PHP/ArticleHeader.php")
        ?>
		<div itemscope itemtype="http://schema.org/Article"  class="articles">
			<?php require_once("Text.php")?>
			<?php require_once($root."/PHP/Call to action.php")?>
			<?php
	              $datePublished = "2018-11-24";
	              require_once($root."/PHP/ArticleInfo.php")
			?>
		</div>
	<?php
       $root = $_SERVER['DOCUMENT_ROOT'];
	    $content = "
	      <ul>
		     <li><i data-open='1' class='fa fa-caret-right' aria-hidden='true'></i><a href='#1'>9 методов, которые увеличат эффективность холодного звонка</a>
			      <ul>
				     <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#1.1'>Зачем настраиваться перед звонком</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#1.2'>Локальная цель</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#1.3'>Чего хочет клиент</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#1.4'>Скрипт звонка</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#1.5'>Подготовка к звонку</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#1.6'>Звоните потенциальным клиентам</a></li>
					  <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#1.7'>Спрашивайте разрешения</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#1.8'>Зачем нужен секретарь</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#1.9'>Ведите статистику</a></li>
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