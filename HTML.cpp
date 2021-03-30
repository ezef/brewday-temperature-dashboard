#include "HTML.h"

String indexHTML(){
String full_html = R"=====(
 <html>
	<head>
		<title>Brewday temperature dashboard</title>
		<meta charset="utf-8">
		<meta name="viewport" content="width=device-width, initial-scale=1">
		<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
		<link rel="stylesheet" href="bootstrap.min.css">

		<style>
			.label-indicator {
				font-size: 26px;
			}
			.mr2 {
				margin-right: 2em;
			}
			.give-air {
				margin-top: 20px;
				margin-bottom: 20px;
			}

			.fade-in {
				-webkit-animation: fade-in 0.3s cubic-bezier(0.390, 0.575, 0.565, 1.000) both;
				animation: fade-in 0.3s cubic-bezier(0.390, 0.575, 0.565, 1.000) both;
			}
			/**
			* ----------------------------------------
			* animation fade-in http://animista.net
			* ----------------------------------------
			*/
			@-webkit-keyframes fade-in {
				0% {opacity: 0;}
				100% {opacity: 1;}
			}
			@keyframes fade-in {
				0% {opacity: 0;}
				100% {opacity: 1;}
			}

		</style>
	</head>

	<body>
		<div class="container">

			<div class="panel panel-default" style="margin-top:10px;">
				<div class="panel-heading">Lecturas</div>
				<div class="panel-body row give-air">

					<div class="col-xs-6">
						
						<span class="mr2">
							Sensor 1:  <span class="label label-primary label-indicator fade-in"><span id="temperature1"></span>º</span>
						</span>
					</div>
					
					<div class="col-xs-6">
						<span class="mr2">
							Sensor 2:  <span class="label label-default label-indicator fade-in"><span id="temperature2"></span>º</span>
						</span>
					</div>
				</div>
			</div>

		</div>

		<script>
			var xmlhttp = new XMLHttpRequest();
			var url = '/get-temperatures'; // TODO change URL to /get-temperatures

			var $temp1_label = document.getElementById("temperature1");
			var $temp2_label = document.getElementById("temperature2");

			xmlhttp.onreadystatechange = function() {
				if (this.readyState == 4 && this.status == 200) {
					var parsed_values = JSON.parse(this.responseText);
					
					$temp1_label.innerHTML = parsed_values.temperature1;
					$temp1_label.classList.add("fade-in");
					
					$temp2_label.innerHTML = parsed_values.temperature2;
					$temp2_label.classList.add("fade-in");
				}

				setTimeout(function(){
					$temp1_label.classList.remove("fade-in");
					$temp2_label.classList.remove("fade-in");
				}, 500);
			};

			fetchTemperatures();
			function fetchTemperatures(){
				xmlhttp.open("GET", url, true);
				xmlhttp.send();
				setTimeout(function(){fetchTemperatures()}, 2000);
			}

		</script>
	</body>
</html>
)=====";

  return full_html;
}

void bootstrap()
{
  File file = SPIFFS.open("/bootstrap.min.css.gz", "r"); 
  size_t sent = server.streamFile(file, "text/css");
}
