<body>
	<style>
		* {
		    font-family: Arial, Helvetica, sans-serif;
		    margin: 0;
		    padding: 0;
		}

		h2 {
		    text-align: center;
		    padding: 10px;
		}

		h3 {
		    text-align: center;
		    padding: 10px;
		    font-weight: normal;
		    font-style: italic;
		}
	</style>
	<?php
		print("<h2>REFRESH PAGE</h2>");
		$filename = "counter.txt";

		$file = fopen($filename, "r");
		$hits = fscanf($file, "%d");
		fclose($file);
		$hits[0]++;
		
		$file = fopen($filename, "w");
		fprintf($file, "%d", $hits[0]);
		fclose($file);
		print("<h3>Total number of views: $hits[0]<h3>");
	?>
</body>
