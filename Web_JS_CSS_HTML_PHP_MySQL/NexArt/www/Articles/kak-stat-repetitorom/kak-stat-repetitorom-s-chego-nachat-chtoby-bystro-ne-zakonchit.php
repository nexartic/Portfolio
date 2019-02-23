<!DOCTYPE html>
<?php
      $title = "Что нужно чтобы стать репетитором. С чего начать, чтобы быстро не закончить.|nexart";
      $discription = "Давно думаете о том, что нужно чтобы стать репетитором? Но все никак не наберетесь смелости начать. Заходите, и кроме хорошего настроения вы получите 6 полезных советов как начать зарабатывать репетитором.";
      $keywords = "как стать репетитором ученик преподавать учить";
      $main_select = "false";
      $reg_select = "false";
      $path_AllArticles = "/index.php";
      $root = $_SERVER['DOCUMENT_ROOT'];
      require_once($root."/PHP/Header_up.php");
      require_once($root."/PHP/Link.php");
      require_once($root."/PHP/Header_bottom.php");
    ?>

         <?php 
            $h1 = "Что нужно чтобы стать репетитором. С чего начать, чтобы быстро не закончить.";
            $background_image = "/Articles/kak-stat-repetitorom/img/kak-stat_repetitorom.jpg";
            $meta_width = "1400";
            $meta_height = "400";
            $alt = "Как стать репетитором";
            $border_bottom = "linear-gradient(to right, #320800 20%, #531b02 52%, #f7d188 80%);";
            require_once($root."/PHP/ArticleHeader.php")
        ?>
		<div class="articles" itemscope itemtype="http://schema.org/Article" class="articles">
			<?php require_once("Text.php")?>
			<?php require_once($root."/PHP/Call to action.php")?>
			<?php
	              $datePublished = "2018-11-18";
	              require_once($root."/PHP/ArticleInfo.php")
			?>
		</div>
	<?php
       $root = $_SERVER['DOCUMENT_ROOT'];
	   $content = "
	      <ul>
		     <li><i data-open='1' class='fa fa-caret-right' aria-hidden='true'></i><a href='#1'>6 советов тем, кто хочет стать репетитором</a>
			      <ul>
				     <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#1.1'> Как определиться c вашей аудиторией</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#1.2'>Как работать с толпой</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#1.3'>Заманивайте новых клиентов</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#1.4'>Какой предмет выбрать</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#1.5'>Показывайте результат</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#1.6'>Продайте себя</a></li>
				  </ul>
			 </li>
			 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#2'>Online или Ofline репетиторство?</a></li>
			 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#3'>Сложности, с которыми вы столкнетесь</a></li></li>
			 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#4'>Плюсы и минусы</a></li></li>
		  </ul>
	   ";
	   require_once($root."/PHP/Footer.php");
	   require_once($root."/PHP/Footer_bottom.php");
       require_once($root."/PHP/Scripts.php");
	?>
	</body>
</html>