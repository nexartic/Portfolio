<!DOCTYPE html>
<?php
      $title = "Простые способы заработать в интернете. Вжух и вы на 1000 рублей богаче|nexart";
      $discription = "Давно ищете легкий способ поднять деньжат в интернете ? Или вы только начали искать ? Неважно. В любом случае эта статья будет вам интересна. Кликай по ссылке.";
      $keywords = "просто легко заработать немного денег интернет";
      $main_select = "false";
      $reg_select = "false";
      $path_AllArticles = "/index.php";
      $root = $_SERVER['DOCUMENT_ROOT'];
      require_once($root."/PHP/Header_up.php");
      require_once($root."/PHP/Link.php");
      require_once($root."/PHP/Header_bottom.php");
    ?>
        
        <?php 
            $h1 = "Простые способы заработать в интернете. Вжух и вы на 1000 рублей богаче.";
            $background_image = "/Articles/prostoy-sposob-zarabotat-v-internete/img/prostoy-sposob-zarabotat-million.jpg";
            $meta_width = "1400";
            $meta_height = "400";
            $alt = "Девушка работает за ноутбуком в интернете";
            $border_bottom = "linear-gradient(to right, #e1ddeb 25%, #54545c 52%, #d9d6e1 80%);";
            require_once($root."/PHP/ArticleHeader.php")
        ?>
		<div class="articles" itemscope itemtype="http://schema.org/Article" class="articles">
			<?php require_once("Text.php")?>
			<?php require_once($root."/PHP/Call to action.php")?>
			<?php
	              $datePublished = "2018-12-10";
	              require_once($root."/PHP/ArticleInfo.php")
			?>
		</div>
	<?php
       $root = $_SERVER['DOCUMENT_ROOT'];
	   $content = "
	      <ul>
			 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#1'>GPT - сайты</a></li>
			 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#2'>Web - тестирование</a></li></li>
			 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#3'>Глобус Интерком</a></li>
			 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#4'>Как перейти на удаленную работу</a></li></li>
			 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#5'>Яндекс.Толока</a></li></li>
		  </ul>
	   ";
	   require_once($root."/PHP/Footer.php");
	   require_once($root."/PHP/Footer_bottom.php");
       require_once($root."/PHP/Scripts.php");
	?>
	</body>
</html>