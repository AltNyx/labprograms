<?php
	$con=mysqli_connect("localhost","root","","student");
	if($con->connect_error)
	{
		die("failed bcos".$con->connect_error);
	}
else
{
	echo "connection is successfull<br>";

$a=[];
$b=[];
$c=[];
$q="select * from student";
$res=mysqli_query($con,$q);
echo "BEFORE SORTING<br>";
echo "<table border='1'> <tr><th> USN</th><th> NAME</th><th>Address</th></tr>";
while($row=mysqli_fetch_assoc($res))
{
	echo "<tr>";
	echo "<td>".$row["USN"]."</td>";
	echo "<td>".$row["NAME"]."</td>";
	echo "<td>".$row["ADDRESS"]."</td>";
	echo "</tr>";
	array_push($a,$row["USN"]);
}
echo "</table>";
$n=count($a);
for($i=0;$i<$n-1;$i++)
{
	$pos=$i;
	for($j=$i+1;$j<$n;$j++)
      {
      	if($a[$j]<$a[$pos])
      		$pos=$j;

      }
      $temp=$a[$i];
      $a[$i]=$a[$pos];
      $a[$pos]=$temp;
}
$q="select * from student";
$res=$con->query($q);
while($row=$res->fetch_assoc())
{
	for($i=0;$i<$n;$i++)
    {
    	if($a[$i]==$row["USN"])
    	{
    		$b[$i]=$row["NAME"];
    		$c[$i]=$row["ADDRESS"];
    	}
    }
}
echo "AFTER SORTING<br>";
echo "<table border='1'> <tr><th> USN</th><th> NAME</th><th>Address</th></tr>";
for($i=0;$i<$n;$i++)
{
	echo "<tr>";
	echo "<td>".$a[$i]."</td>";
	echo "<td>".$b[$i]."</td>";
	echo "<td>".$c[$i]."</td>";
	echo "</tr>";
}
echo "</table>";
$con->close();//mysqli_close($con)
}
?>