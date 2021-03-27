#include "HTML.h"


String indexHTML(){
String full_html = R"=====(

  INDEX HTML HERE


)=====";

/*
  // temperature_read
  full_html.replace("{{temperature_read}}", (const char *) &tempsensada1);

  // current_set_indicator
  full_html.replace("{{current_set_indicator}}", (const char *) &tempset1);

  // actuator_indicator
  const char * actuator_on_html = "<span class='label label-success label-indicator'>On</span>";
  const char * actuator_off_html = "<span class='label label-danger label-indicator'>Off</span>";
  full_html.replace("{{actuator_indicator}}", relay1 ? actuator_on_html : actuator_off_html );


  const char * mode_indicator_on_html = "<span class='label label-success pull-right'>Activado</span>";
  const char * mode_indicator_off_html = "<span class='label label-warning pull-right'>Desactivado</span>";

  // simple_mode_active_indicator
  full_html.replace("{{simple_mode_active_indicator}}", temperatureControlMode == SIMPLE_MODE ? mode_indicator_on_html : mode_indicator_off_html );

  // stepped_mode_active_indicator
  full_html.replace("{{stepped_mode_active_indicator}}", temperatureControlMode == STEPPED_MODE ? mode_indicator_on_html : mode_indicator_off_html );

  // stepped_mode_days_started and stepped_mode_hours_started

  const char * time_since_stepped_mode_started_html = "<br><span class='label label-success pull-right'>Iniciado hace {{stepped_mode_days_started}} dias y {{stepped_mode_hours_started}} horas</span>";
  full_html.replace("{{time_since_stepped_mode_started_html}}", temperatureControlMode == STEPPED_MODE ? time_since_stepped_mode_started_html : "" );

  if (temperatureControlMode == STEPPED_MODE){
    int days_passed = hoursPassedSinceSteppedControlModeStarted / 24;
    int hours_passed = hoursPassedSinceSteppedControlModeStarted - (days_passed * 24);
    full_html.replace("{{stepped_mode_days_started}}", (const char *) &days_passed );
    full_html.replace("{{stepped_mode_hours_started}}", (const char *) &hours_passed );
  }

  full_html.replace("{{step_1_temperature}}", temperatureSteps[0]->temperature > 0 ? (const char*) temperatureSteps[0]->temperature : "0");
  full_html.replace("{{step_2_temperature}}", temperatureSteps[1]->temperature > 0 ? (const char*) temperatureSteps[1]->temperature : "0");
  full_html.replace("{{step_3_temperature}}", temperatureSteps[2]->temperature > 0 ? (const char*) temperatureSteps[2]->temperature : "0");
  full_html.replace("{{step_4_temperature}}", temperatureSteps[3]->temperature > 0 ? (const char*) temperatureSteps[3]->temperature : "0");
  full_html.replace("{{step_5_temperature}}", temperatureSteps[4]->temperature > 0 ? (const char*) temperatureSteps[4]->temperature : "0");
  full_html.replace("{{step_6_temperature}}", temperatureSteps[5]->temperature > 0 ? (const char*) temperatureSteps[5]->temperature : "0");
  full_html.replace("{{step_7_temperature}}", temperatureSteps[6]->temperature > 0 ? (const char*) temperatureSteps[6]->temperature : "0");
  full_html.replace("{{step_8_temperature}}", temperatureSteps[7]->temperature > 0 ? (const char*) temperatureSteps[7]->temperature : "0");
  full_html.replace("{{step_9_temperature}}", temperatureSteps[8]->temperature > 0 ? (const char*) temperatureSteps[8]->temperature : "0");
  full_html.replace("{{step_10_temperature}}", temperatureSteps[9]->temperature > 0 ? (const char*) temperatureSteps[9]->temperature : "0");

  full_html.replace("{{step_1_hour}}", temperatureSteps[0]->temperature > 0 ? (const char*) temperatureSteps[0]->hours : "0");
  full_html.replace("{{step_2_hour}}", temperatureSteps[1]->temperature > 0 ? (const char*) temperatureSteps[1]->hours : "0");
  full_html.replace("{{step_3_hour}}", temperatureSteps[2]->temperature > 0 ? (const char*) temperatureSteps[2]->hours : "0");
  full_html.replace("{{step_4_hour}}", temperatureSteps[3]->temperature > 0 ? (const char*) temperatureSteps[3]->hours : "0");
  full_html.replace("{{step_5_hour}}", temperatureSteps[4]->temperature > 0 ? (const char*) temperatureSteps[4]->hours : "0");
  full_html.replace("{{step_6_hour}}", temperatureSteps[5]->temperature > 0 ? (const char*) temperatureSteps[5]->hours : "0");
  full_html.replace("{{step_7_hour}}", temperatureSteps[6]->temperature > 0 ? (const char*) temperatureSteps[6]->hours : "0");
  full_html.replace("{{step_8_hour}}", temperatureSteps[7]->temperature > 0 ? (const char*) temperatureSteps[7]->hours : "0");
  full_html.replace("{{step_9_hour}}", temperatureSteps[8]->temperature > 0 ? (const char*) temperatureSteps[8]->hours : "0");
  full_html.replace("{{step_10_hours}}", temperatureSteps[9]->temperature > 0 ? (const char*) temperatureSteps[9]->hours : "0");
  */

  return full_html;
}

void bootstrap()
{
  File file = SPIFFS.open("/bootstrap.min.css.gz", "r"); 
  size_t sent = server.streamFile(file, "text/css");
}
