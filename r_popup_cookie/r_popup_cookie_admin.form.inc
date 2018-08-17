<?php

function r_popup_cookie_admin_form($form, &$form_state) {
  $form               = array();
  $defaults           = array('value' => 'Enter a message', 'format' => filter_default_format());

  $year               = variable_get('Year'             , '2018'                                );     
  $month              = variable_get('Month'            , '01'                                  );
  $date               = variable_get('Date'             , '01'                                  );
  $hour               = variable_get('Hour'             , '01'                                  );
  $minutes            = variable_get('Minutes'          , '01'                                  );
  $kill_cookies       = variable_get('cookie_timer'     , '259200000'                           );
  $cookie_key         = variable_get('cookie_key'       , 'jobs-board-seen-1'                   );

  $summary            = variable_get('api_summary'      , 0                                     );
  $field              = variable_get('api_field'        , 0                                     );

  $emediate_code      = variable_get('emediate_code'    , 34954                                 );
  $background_opacity = variable_get('background_opacity', 0.1 );

  $cookie_popup_enable  = variable_get('cookie_popup_msg_popup'    , 0                                     );

  $arr_allowed  = array(0 => 'None');
  $arr_summary  = array(0 => 'None');
  $arr_field    = array();

  // dsm(field_info_field_map() );

  foreach(field_info_field_map() as $key => $value) {
    if ( $value['type'] == 'list_boolean' ) { 
      $arr_allowed[$key] = $key; 
    }
    if ( in_array($value['type'], array('text_long', 'text_with_summary')) ) {
      $arr_summary[$key] = $key;
      $arr_field[$key]   = $key;
    }
  }

  $form['verify_setup_form'] = array(
    '#type' => 'vertical_tabs',
  );

  $form['verification'] = array(
    '#title'       => t('Date and Time Settings'),
    '#type'        => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed'   => FALSE,
    '#group'       => 'verify_setup_form', 
  );

  $form['verification']['Year'] = array(
    '#title'         => t('Year'),
    '#type'          => 'textfield',
    '#size'          => 50,
    '#default_value' => $year,
    '#required'      => FALSE,
  );

  $form['verification']['Month'] = array(
    '#title'         => t('Month'),
    '#type'          => 'textfield',
    '#size'          => 50,
    '#default_value' => $month,
    '#required'      => FALSE,
  );

  $form['verification']['Date'] = array(
    '#title'         => t('Day'),
    '#type'          => 'textfield',
    '#size'          => 50,
    '#default_value' => $date,
    '#required'      => FALSE,
  );

  $form['verification']['Hour'] = array(
    '#title'         => t('Hour'),
    '#type'          => 'textfield',
    '#size'          => 50,
    '#default_value' => $hour,
    '#required'      => FALSE,
  );

  $form['verification']['Minutes'] = array(
    '#title'         => t('Minutes'),
    '#type'          => 'textfield',
    '#size'          => 50,
    '#default_value' => $minutes,
    '#required'      => FALSE,
  );

  $form['verification']['cookie_timer'] = array(
    '#title'         => t('Popup cookies expires (in milliseconds)'),
    '#type'          => 'textfield',
    '#size'          => 50,
    '#default_value' => $kill_cookies,
    '#required'      => FALSE,
  );

  $form['verification']['cookie_key'] = array(
    '#title'         => t('Generate unique cookie key for popup'),
    '#type'          => 'textfield',
    '#size'          => 50,
    '#default_value' => $cookie_key,
    '#required'      => FALSE,
  );

  $form['verification']['emediate_code'] = array(
    '#title'         => t('Insert Emediate code key'),
    '#type'          => 'textfield',
    '#size'          => 50,
    '#default_value' => $emediate_code,
    '#required'      => TRUE,
  );

  $form['verification']['background_opacity'] = array(
    '#title'         => t('Background Overlay'),
    '#type'          => 'textfield',
    '#size'          => 50,
    '#default_value' => $background_opacity,
    '#required'      => TRUE,
  );

  $form['check']['cookie_popup_enable'] = array(
    '#title'         => t('Enable Popup'),
    '#type'          => 'checkbox',
    '#default_value' => $cookie_popup_enable,
    '#required'      => FALSE, 
  );
  return system_settings_form($form);
}