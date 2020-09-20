<?php //countries.php
	header('Content-Type: application/json');
	$data = array();
	$countries = array('Afghanistan', 'Albania', 'Algeria', 'Andorra', 'India', 'United States of America');
	if (isset($_GET['term'])) {
		foreach ($countries as $country) {
			if (stripos($country, $_GET['term']) !== false) {
				$data[] = $country;
			}
		}
	}
	echo json_encode($data);
?>
