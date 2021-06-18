
<head>
	<style>
		body {
			font-family: Arial, Helvetica, sans-serif;
			background-color: <?php echo date("#His");?>;
			display: flex;
			align-items: center;
			justify-content: center;
		}
        	.clock {
			color: white;
			font-size: 70px;
			font-style: italic;
		}
		.color {
			position: absolute;
			bottom: 0;
			left: 0;
			padding: 10px;
			color: white;
			font-size: 20px;
			font-style: italic;
		}
	</style>
    <meta http-equiv="refresh" content="1">
	<?php date_default_timezone_set("Asia/Kolkata"); ?>
    <p class="clock"><?php echo date("H:i:s");?></p>
	<p class="color">Color: <?php echo date("#His");?></p>
</head>