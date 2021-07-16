<!DOCTYPE html>
<html lang"en">

<head>
    <title>Document</title>
    <link rel="preconnect" href="https://fonts.gstatic.com">
    <link href="https://fonts.googleapis.com/css2?family=Roboto:ital@1&display=swap" rel="stylesheet">
    <link rel="stylesheet" href="style.css">
</head>
<body>
    <form class="form" action="calculatorPHP.php" method="post">
        <table>
            <caption><h2>Simple Calculator</h2></caption>
            <tr>
                <td><input type="text" placeholder="Enter first number" name="num1"/></td>
            </tr>
            <tr>
                <td><input type="text" placeholder="Enter second number" name="num2"/></td>
            </tr>
            <tr>
                <td><Button type="submit" name="submit">Calculate</Button></td>
            </tr>
    </form>

    <?php
    if (isset($_POST['submit'])) {
        $num1 = $_POST['num1'];
        $num2 = $_POST['num2'];

        if (is_numeric($num1) and is_numeric($num2)) {
            echo "<tr><td><p>Addition: ".($num1+$num2)."</p></td></tr>";
            echo "<tr><td><p>Subtraction: ".($num1-$num2)."</p></td></tr>";
            echo "<tr><td><p>Multiplication: ".($num1*$num2)."</p></td></tr>";
            echo "<tr><td><p>Division: ".($num1/$num2)."</p></td></tr>";
            echo "</table>";
        } else {
            echo "<script> alert('Enter VALID NUMBER'); </script>";
        }
    }
    ?>
</body> 
</html>