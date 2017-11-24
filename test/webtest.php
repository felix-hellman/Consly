<?php
$json = json_encode(
    array(
        'GET' => array(
            'Title' => isset($_GET['Title']) ? $_GET['Title'] : null,
            'Title2' => isset($_GET['Title2']) ? $_GET['Title2'] : null,
            'Data' => isset($_GET['Data']) ? $_GET['Data'] : null,
            'Data2' => isset($_GET['Data2']) ? $_GET['Data2'] : null
        ),
        'POST' => array('Title' => isset($_POST['Title']) ? $_GET['Title'] : null,
            'Title2' => isset($_POST['Title2']) ? $_GET['Title2'] : null,
            'Data' => isset($_POST['Data']) ? $_POST['Data'] : null,
            'Data2' => isset($_POST['Data2']) ? $_POST['Data2'] : null
        )
    )
);

print_r(json_decode($json));
