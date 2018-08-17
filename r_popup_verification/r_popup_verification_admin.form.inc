<?php

function r_popup_verification_admin_form($form, &$form_state) {
  $form        = array();
  $defaults    = array('value' => 'Enter a message', 'format' => filter_default_format());

  $regex_df    = variable_get('regex_pattern'    , '([a])\w+'                            );     
 
  $msg_body    = variable_get('api_msg_body'     , $defaults                             );
  $msg_popup   = variable_get('api_msg_popup'    , 0                                     );

  $summary     = variable_get('api_summary'      , 0                                     );
  $field       = variable_get('api_field'        , 0                                     );


  $pri_field   = variable_get('api_private'      , 0                                     );
  $msg_title   = variable_get('api_msg_title'    , 'Subscription Content'                );
  $msg_before  = variable_get('api_msg_before'   , 'Hi !firstname. Glad to see you back.');
  $msg_body    = variable_get('api_msg_body'     , $defaults                             );
  $msg_popup   = variable_get('api_msg_popup'    , 0                                     );

  $arr_allowed = array(0 => 'None');
  $arr_summary = array(0 => 'None');
  $arr_field   = array();

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
    '#title'       => t('Verfication Content Settings'),
    '#type'        => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed'   => FALSE,
    '#group'       => 'verify_setup_form'
  );

  $form['verification']['regex_pattern'] = array(
    '#title'         => t('Regular Regular'),
    '#type'          => 'textfield',
    '#size'          => 50,
    '#default_value' => $regex_df,
    '#required'      => FALSE,
  );

  $form['field'] = array(
    '#title'       => t('Field Settings'),
    '#type'        => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed'   => TRUE,
    '#group'       => 'verify_setup_form'
  );

  $form['field']['api_private'] = array(
    '#title'         => t('Selected field to be used when checking page is private'),
    '#type'          => 'select',
    '#options'       => $arr_allowed,
    '#default_value' => $pri_field,
  );

  $form['field']['api_summary'] = array(
    '#title'         => t('Selected field to be displayed as summary'),
    '#type'          => 'select',
    '#options'       => $arr_summary,
    '#default_value' => $summary,
  );

  $form['field']['api_field'] = array(
    '#title'         => t('Selected fields to be private'),
    '#type'          => 'select',
    '#multiple'      => true,
    '#options'       => $arr_field,
    '#default_value' => $field,
  );

  $form['message'] = array(
    '#title'       => t('Messaging'),
    '#type'        => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed'   => TRUE,
    '#group'       => 'verify_setup_form'
  );

  $form['message']['api_msg_title'] = array(
    '#title'         => t('Message Title'),
    '#type'          => 'textfield',
    '#size'          => 50,
    '#default_value' => $msg_title,
    '#required'      => FALSE,
  );

  $form['message']['api_msg_before'] = array(
    '#title'         => t('Message before'),
    '#type'          => 'text_format',
    '#size'          => 50,
    '#default_value' => $msg_before['value'],
    '#required'      => FALSE,
  );

  $form['message']['api_msg_body'] = array(
    '#type'          => 'text_format',
    '#title'         => t('Message Body'),
    '#default_value' => $msg_body['value'],
    '#format'        => $msg_body['format']
  );

  $form['message']['api_msg_popup'] = array(
    '#title'         => t('Enable Popup'),
    '#type'          => 'checkbox',
    '#default_value' => $msg_popup,
    '#required'      => FALSE, 
  );

  return system_settings_form($form);
}