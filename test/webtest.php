<?php
if (!empty($_GET)) {
    $requests['GET'] = $_GET;
} elseif (!empty($_POST)) {
    $requests['POST'] = $_POST;
}

if (isset($requests)) {
    $json = json_encode($requests, JSON_PRETTY_PRINT);
    echo "$json\n";
} else {
    echo "No GET or POST parameter given\n";
}
