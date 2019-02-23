<!DOCTYPE html>
<?php
      $title = "Приложения для записи видео с экрана компьютера. 8 бесплатных видеорекордеров|nexart";
      $discription = "8 Приложений для записи видео с экрана компьютера. А также способы как записать видео с экрана компьютера без специальных программ. Кликай по ссылке.";
      $keywords = "Приложения запись видео экрана компьютера бесплатно";
      $main_select = "false";
      $reg_select = "false";
      $path_AllArticles = "/index.php";
      $root = $_SERVER['DOCUMENT_ROOT'];
      require_once($root."/PHP/Header_up.php");
      require_once($root."/PHP/Link.php");
      require_once($root."/PHP/Header_bottom.php");
    ?>
        <?php 
            $h1 = "Приложения для записи видео с экрана компьютера. 8 бесплатных видеорекордеров";
            $background_image = "/Articles/prilozheniya-dlya-zapisi-video-s-ekrana-kompyutera-besplatnye/img/videocamera.jpg";
            $meta_width = "1400";
            $meta_height = "400";
            $alt = "Приложения для записи видео с экрана компьютера";
            $border_bottom = "linear-gradient(to right, #7ca4ac 5%, #aa9882 40%, #1b2838 70%);";
            require_once($root."/PHP/ArticleHeader.php")
        ?>
		<div itemscope itemtype="http://schema.org/Article"  class="articles">
			<?php require_once("Text.php")?>
			<?php require_once($root."/PHP/Call to action.php")?>
			<?php
	              $datePublished = "2018-11-23";
	              require_once($root."/PHP/ArticleInfo.php")
			?>
		</div>
	<?php
       $root = $_SERVER['DOCUMENT_ROOT'];
		$content = "
	      <ul>
		     <li><i data-open='1' class='fa fa-caret-right' aria-hidden='true'></i><a href='#1'>Приложения на Windows</a>
			      <ul>
				     <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#1.1'>OBS Studio</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#1.2'>Action!</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#1.3'>Tiny Take</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#1.4'>Ice cream Screen Recorder</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#1.5'>DVD VideoSoft Screen</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#1.6'>Activepresenter</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#1.7'>Ezvid</a></li>
					  <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#1.8'>Hypercam</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#1.9'>Shadow Play</a></li>
					 <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#1.10'>Xsplit Broadcaster</a></li>
				  </ul>
			 </li>
			 <li><i data-open='1' class='fa fa-caret-right' aria-hidden='true'></i><a href='#2'>Приложения на Mac</a>
			     <ul>
				     <li><i data-open='1' class='fa fa-caret-right' aria-hidden='true'></i><a href='#2.1'>QuickTime</a></li>
				  </ul>
			 </li>
			 <li><i data-open='1' class='fa fa-caret-right' aria-hidden='true'></i><a href='#3'>Приложения на iPone</a>
			     <ul>
				     <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#3.1'>Airshou</a></li>
				  </ul>
			 </li>
			 <li><i data-open='1' class='fa fa-caret-right' aria-hidden='true'></i><a href='#4'>Как записать видео без сторонних программ</a>
			     <ul>
				     <li><i class='fa fa-circle' aria-hidden='true'></i><a href='#4.1'>PowerPoint</a></li>
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