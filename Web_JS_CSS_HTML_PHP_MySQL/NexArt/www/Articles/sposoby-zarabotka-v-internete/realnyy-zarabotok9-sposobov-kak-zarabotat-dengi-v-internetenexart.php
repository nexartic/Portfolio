<!DOCTYPE html>
<?php
      $title = "Cпособы заработка денег в интернете. 9 способов заработка в сети|nexart";
      $discription = "Cпособы заработка денег в интернете. Заходите и вы  поймете, почему вечно нехватает денег. И как изменить эту ситуацию";
      $keywords = "реальный заработок интернет деньги быстро";
      $main_select = "false";
      $reg_select = "false";
      $path_AllArticles = "/index.php";
      $root = $_SERVER['DOCUMENT_ROOT'];
      require_once($root."/PHP/Header_up.php");
      require_once($root."/PHP/Link.php");
      require_once($root."/PHP/Header_bottom.php");
    ?>
         <?php 
            $h1 = "Cпособы заработка денег в интернете. 9 способов заработка в сети";
            $background_image = "/Articles/sposoby-zarabotka-v-internete/img/dengi.jpg";
            $meta_width = "1400";
            $meta_height = "400";
            $alt = "Cпособы заработка денег в интернете";
            $border_bottom = "linear-gradient(to right, #2e2e2e 5%, #795008 50%, #2e2e2e 80%);";
            require_once($root."/PHP/ArticleHeader.php")
        ?>
		<div itemscope itemtype="http://schema.org/Article" class="articles">
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
		     <li><i data-open='1' class='fa fa-circle' aria-hidden='true'></i><a href='#1'>Партнерские программы</a></li>
			 <li><i data-open='1' class='fa fa-circle' aria-hidden='true'></i><a href='#2'>Написание текстов</a>
			 </li>
			 <li><i data-open='1' class='fa fa-circle' aria-hidden='true'></i><a href='#3'>Как зарабатывать, продавая фотографий</a>
			 </li>
			 <li><i data-open='1' class='fa fa-circle' aria-hidden='true'></i><a href='#4'>Файловые хостинги</a></li>
			 <li><i data-open='1' class='fa fa-circle' aria-hidden='true'></i><a href='#5'>Авито</a></li>
			 <li><i data-open='1' class='fa fa-circle' aria-hidden='true'></i><a href='#6'>Продажа услуг</a></li>
			 <li><i data-open='1' class='fa fa-circle' aria-hidden='true'></i><a href='#7'>Клуб покупателей</a></li>
			 <li><i data-open='1' class='fa fa-circle' aria-hidden='true'></i><a href='#8'>Online-опросы</a></li>
			 <li><i data-open='1' class='fa fa-circle' aria-hidden='true'></i><a href='#9'>Способы для профи</a></li>
		  </ul>
	   ";
	   require_once($root."/PHP/Footer.php");
	   require_once($root."/PHP/Footer_bottom.php");
       require_once($root."/PHP/Scripts.php");
	?>
	</body>
</html>