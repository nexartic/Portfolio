<!DOCTYPE html>
<html lang="en" class="js csstransforms csstransforms3d preserve3d no-ie mdl-js" >
<head>
	<meta charset="UTF-8">
	<title>Memoraps</title>
	<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/normalize/5.0.0/normalize.min.css">
	<link rel="stylesheet" href="CSS/StyleGeneral.css?v=1.0.10">
	<link rel="stylesheet" href="CSS/StyleLeftPanel.css?v=1.0.13">
	<link rel="stylesheet" href="CSS/StyleRightPanel.css?v=1.0.8">
	<link rel="stylesheet" href="CSS/StyleCenterPanel.css?v=1.2.8">
	<link rel="stylesheet" href="CSS/StyleBlock.css?v=1.1.4">
	<link rel="stylesheet" href="CSS/StyleLargeWindow.css?v=1.0.3">
	<link rel="stylesheet" href="build/mediaelementplayer.min.css">
	<script src="https://use.fontawesome.com/5399a799d4.js"></script>
</head>
<body>
	<div id="blackScreen"></div>
	<div id="leftPanel">
		<div id="logo">
			<div class="contain">
			<img src="Image/logo.svg" alt="logo"><span>emoraps</span>
			</div>
		</div>
		<div id="plugin">
			<span>Скачать плагин</span>
		</div>
		
		<div id="center">
		  <ul>
			  <li style="background-color:  #0049BC"><i class="fa fa-bars" aria-hidden="true"></i><span>Главная</span></li>
			  <a href="PHP/Register.php"><li><i class="fa fa-sign-in" aria-hidden="true"></i><span>Регистрация</span></li></a>
			  <li><i class="fa fa-phone" aria-hidden="true"></i><span>Контакты</span></li>
			  <li><i class="fa fa-book" aria-hidden="true"></i><span>О нас</span></li>
		  </ul>
		</div>
		
		<div id="footer">
			<i class="fa fa-vk" aria-hidden="true"></i>
			<i class="fa fa-facebook-square" aria-hidden="true"></i>
			<i class="fa fa-instagram" aria-hidden="true"></i>
			<span>&copy NexArt, <?php echo date('Y') ?></span>
		</div>
	</div>
	
	
	<div id="centerPanel">
		<div id="top">
			<button class="backward"><i class="fa fa-arrow-circle-left" aria-hidden="true"></i></button>
			
			
			<div class="frame" style="overflow: hidden;">
				<ul>
					<li class="folder" data-index="0">
						<i class="fa fa-pencil" aria-hidden="true"></i>
						<input type="text" disabled="disabled" value="Документы" maxlength="14">
				        <button class="remove"><i class="fa fa-times" aria-hidden="true"></i></button>
					</li>
				</ul>
			</div>
			
			<button class="forward"><i class="fa fa-arrow-circle-right" aria-hidden="true"></i></button>
			<button class="add"><i class="fa fa-plus-circle" aria-hidden="true" id="topPlus"></i></button>
		</div>
		<div id="bottom">
			<div class="block" data-index="0">
				<div class="top">
					<i class="fa fa-eraser" aria-hidden="true" role="listbox"></i>
					<i class="fa fa-arrows-alt" aria-hidden="true" role="listbox"></i>
<!--
					<div class="newVideo" >
						<video class="mejs__player" width="100%" height="100%" controls >
							<source src="_ The School of Life_.mp4">
					    </video>
					</div>
-->
				</div>
				<div class="bottom">
					<div class="edit">
						<i class="fa fa-pencil" aria-hidden="true" role="listbox"></i>
					</div>
					
					<div class="share" > 
						<ul>
							<div id="listFolders">
								<div class="container">
									<div class="page">
									</div>
								</div>
							</div>
							<i class="fa fa-share-square-o" aria-hidden="true" role="listbox"></i>
					    </ul>
					</div>
					
					<div class="create">	
						<ul>
							<div class="text" role="list">
						        <i class="fa fa-file-text" aria-hidden="true" role="list"></i>
							</div>
							
							<div class="image" role="list">
							    <i class="fa fa-picture-o" aria-hidden="true" role="list"></i>
								<i class="fa fa-internet-explorer" aria-hidden="true" data-s="extra"></i>
                                <i class="fa fa-folder-open-o" aria-hidden="true" data-s="extra"></i>
							</div>
							
							<div class="video" role="list">
								<i class="fa fa-video-camera" aria-hidden="true" role="list"></i>
							</div>
							
							<div class="music" role="list">
								<i class="fa fa-music" aria-hidden="true" role="list"></i>
							</div>
						</ul>	
						<i class="fa fa-plus" aria-hidden="true" role="listbox"></i>		
					</div>
					
					<div class="cross">
						<i class="fa fa-times" aria-hidden="true" role="listbox"></i>
					</div>
				</div>
			</div>
			
			<div id="fixedInterface">
				<i id="deleteAll" class="fa fa-trash" aria-hidden="true"></i>
			    <i id="bottomPlus" class="fa fa-plus-square" aria-hidden="true"></i>
			</div>
			<div id="largeWindow">
				<div id="fieldLargeWindow">
				</div>
				<div id="toolsLargeWindow">
					<i class="fa fa-times" aria-hidden="true" id="crossLW"></i>
					<i class="fa fa-eraser" aria-hidden="true"></i>
				</div>
		    </div>
		</div>
	</div>
	
	
	<div id="rightPanel">
		<div id="stikers">
			<div class="sticker" id="sticker_1">
			</div>
			<div class="sticker" id="sticker_2">
			</div>
		</div>
		
		<div id="support">
			<div id="search">
			    <i class="fa fa-search" aria-hidden="true"></i>
				<input type="text" placeholder="Поиск">
			</div>
			<form id="form">
				<div id="close"><span>x</span></div>
				<input class="field" type="text" placeholder="Имя">
				<input class="field" type="email" placeholder="Email">
				<textarea placeholder="Сообщение"></textarea>
				<input type="submit" value="Отправить">
			</form>
		</div>
	</div>
	
	<div id="repos" class="repos" data-display="motio,espy,imagesloaded,fpsmeter"></div>
	
	<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
	<script src="build/mediaelement-and-player.min.js"></script>
<!--	<script src="JavaScript/VideoPlayer.js"></script>-->
	<script src="JavaScript/ScriptBlock.js?v=1.1.27"></script>
	<script src="JavaScript/sly.min.js"></script>
	<script src="JavaScript/ScriptFolder.js?v=1.0.7"></script>
</body>
</html>