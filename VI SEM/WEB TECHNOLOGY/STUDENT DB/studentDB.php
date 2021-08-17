<style>
* {
    font-family: Arial, Helvetica, sans-serif;
	margin: 2px;
	padding: 2px;
}
table {
	width: 100%;
	border-collapse: collapse;
    margin-left: auto;
    margin-right: auto;
}

th {
	text-align: left;
}

h4 {
	font-style: italic;
}
</style>

<?php
	$con = mysqli_connect("localhost", "root", "", "STUDENTDB");
	if ($con->connect_error) {
		die("Connection Error".$con->connect_error);
		exit(0);
	}

	echo "<h3>Connection is Successfull</h3><br>";
	
	$usns = [];
	$names = [];
	$addresses = [];

	$query = "SELECT * FROM STUDENT";
	$result = mysqli_query($con, $query);

	while ($row=mysqli_fetch_assoc($result)) {
		array_push($usns, $row["USN"]);
		array_push($names, $row["NAME"]);
		array_push($addresses, $row['ADDRESS']);
	}

	function printArray($usns) {
		for ($i = 0; $i < count($usns); $i++) {
			echo $usns[$i]."<br>";
		}
	}

	function printTable($usns, $names, $addresses) {
		echo "<table border='1'> <tr> <th>USN</th> <th>NAME</th> <th>ADDRESS</th> </tr>";
		for ($i = 0; $i < count($usns); $i++) {
			echo "<tr>";
			echo "<td>".$usns[$i]."</td>";
			echo "<td>".$names[$i]."</td>";
			echo "<td>".$addresses[$i]."</td>";
			echo "</tr>";
		}
		echo "</table>";
	}

	function swap(& $array, $pos1, $pos2) {
		// & symbol is needed since, array is modified
		// in php array is passed by reference, unless its modified
		// if modified a copy is made (aka lazy copy or copy-on-write)
		$temp = $array[$pos1];
		$array[$pos1] = $array[$pos2];
		$array[$pos2] = $temp;
	}

	function selectionSort(& $usns, & $names, & $addresses) {
		$n = count($usns);
		for ($i = 0; $i < $n-1; $i++) {
			$pos = $i;
			for ($j = $i+1; $j < $n; $j++) {
				if ($usns[$j] < $usns[$pos])
					$pos = $j;
			}
			swap($usns, $i, $pos);
			swap($names, $i, $pos);
			swap($addresses, $i, $pos);
		}
	}

	echo "<h4>Before Sorting</h4>";
	printTable($usns, $names, $addresses);

	selectionSort($usns, $names, $addresses);
	
	echo "<br><h4>After Sorting</h4>";
	printTable($usns, $names, $addresses);

	$con->close();
?>