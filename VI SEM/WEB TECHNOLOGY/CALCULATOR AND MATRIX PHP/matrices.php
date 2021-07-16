<!DOCTYPE html>
<html lang="en">
<head>
    <title>Matrices</title>
</head>
<body>
    <style>
        * {
            font-family: Arial;
        }

        b {
            font-style: italic;
        }
    </style>
    <?php
    function printMatrix($matrix) {
        $space = "&nbsp&nbsp";
        foreach($matrix as $row) {
            echo "[". $space;
            foreach($row as $val) {
                echo $val .$space;
            }
            echo "]<br>";
        }
        echo "<br>";
    }

    function addMatrix($matrix1, $matrix2) {
        $result = array();
        for ($i = 0; $i < count($matrix1); $i++) {
            for ($j = 0; $j < count($matrix1[0]); $j++) {
                $result[$i][$j] = $matrix1[$i][$j] + $matrix2[$i][$j];
            }
        }

        printMatrix($result);
    }

    function transposeMatrix($matrix) {
        $result = array();
        for ($i = 0; $i < count($matrix); $i++) {
            for ($j = 0; $j < count($matrix[0]); $j++) {
                $result[$i][$j] = $matrix[$j][$i];
            }
        }

        printMatrix($result);
    }

    function multiplyMatrix($matrix1, $matrix2) {
        $result = array();
        for ($i = 0; $i < count($matrix1); $i++) {
            for ($j = 0; $j < count($matrix2[0]); $j++) {
                $result[$i][$j] = 0;
                for ($k = 0; $k < count($matrix2); $k++) {
                    $result[$i][$j] += $matrix1[$i][$k] * $matrix2[$k][$j];
                }
            }
        }

        printMatrix($result);
    }

    $matrix1 = [
        [1, 2, 3], 
        [4, 5, 6], 
        [7, 8, 9]
    ];
    
    $matrix2 = [
        [7, 8, 9], 
        [4, 5, 6], 
        [1, 2, 3]
    ];

    $n = count($matrix1);
    $m = count($matrix1[0]);

    $p = count($matrix2);
    $q = count($matrix2[0]);

    echo "<b>First Matrix: </b><br>";
    printMatrix($matrix1);

    echo "<b>Second Matrix: </b><br>";
    printMatrix($matrix2);

    echo "<b>The Transpose of the first matrix is: </b>"."<br/>";
    transposeMatrix($matrix1);

    if (($n == $p) and ($m == $q)) {
        echo "<b>The Addition of first and second matrix is: </b>"."<br/>";
        addMatrix($matrix1, $matrix2);
    }

    if ($m == $p) {
        echo "<b>The Multiplication of the first and second matrix is: </b>"."<br/>";
        multiplyMatrix($matrix1, $matrix2);
    }
    ?>
</body>
</html>