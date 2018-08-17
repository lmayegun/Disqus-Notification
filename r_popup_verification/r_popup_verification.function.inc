<?php 



function _check_private($id) {
  $id = intval($id);
  $field = variable_get('api_private', false);
  if ( $field && field_info_field($field) && is_int($id) ) {
    $query1 = db_select('field_data_' . $field, 'pl');
    $query1 ->condition('pl.entity_id', $id)
            ->fields('pl', array($field . '_value'));
    $result = $query1->execute()->fetchField();
    $result = isset($result) ? $result : false;
    return $result;
  }
  return ;
}


function _get_node_id(){
  if ( arg(0) == 'node' && is_numeric(arg(1)) ) {
    return arg(1);
  } else {
    return 0;
  }
}

function _helloWorld(){
	return ("helloWorld");
}

