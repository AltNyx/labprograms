<body>
    <style>
        * {
            font-family: Arial, Helvetica, sans-serif;
            margin: 0;
            padding: 0;
        }

        h1 {
            padding: 2px 10px;
            font-style: italic;
        }

        h4 {
            padding: 2px 10px;
            font-weight: normal;
        }
    </style>
    <?php
        $statesText = "Mississippi Alabama Texas Massachusetts Kansas";
        $states = explode(' ', $statesText);
        $statesList = [];

        function printArray($states) {
            ksort($states);
            foreach($states as $idx => $value)
            print("<h4>STATES[$idx] = $value</h4>");
        }

        echo "<br><h1>Original Array</h1><br>";
        printArray($states);
        
        foreach($states as $state) {
            if (preg_match('/xas$/', $state)) $statesList[0] = $state; #ends with xas
            if (preg_match('/^k.*s$/i', $state)) $statesList[1] = $state; # starts with k and ends with s (ignore case)
            if (preg_match('/^M.*s$/', $state)) $statesList[2] = $state; # starts with M and ends with s
            if (preg_match('/a$/', $state)) $statesList[3] = $state; # ends with a
        }

        echo "<br><h1>Result Array</h1><br>";
        printArray($statesList);
    ?>
</body>