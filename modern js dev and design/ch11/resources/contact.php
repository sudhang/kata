<?php
	$reply = 'Thank you for your views';
	if ( !(isset($_POST['name'], $_POST['email'], $_POST['comments']))) {
		$reply = 'All fields are required';
	}
	echo $reply
?>
