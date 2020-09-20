<?php
	header('Content-Type: application/json');
	$curl = curl_init('http://www.google.com/finance/info?infotype=infoquoteall&q=AAPL');
	curl_setopt($curl, CURLOPT_RETURNTRANSFER, 1);
	$result = curl_exec($curl);
	curl_close($curl);
	print substr($result, 3);
?>
