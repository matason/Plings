<?php
// $Id$

/**
 * @file
 * Menu and form callbacks.
 */

/**
 * Provide an admin form for Plings settings.
 */
function plings_admin_form($form_state) {
  // Protocol for fetching Plings.
  $form['plings_protocol'] = array(
    '#type' => 'select',
    '#title' => t('Protocol'),
    '#description' => t('Choose the protocol to use when fetching Plings.'),
    '#options' => drupal_map_assoc(array('http', 'https'), 't'),
    '#default_value' => variable_get('plings_protocol', 'http'),
  );

  // Plings requires an API Key to work.
  $form['plings_api_key'] = array(
    '#type' => 'textfield',
    '#title' => t('API Key'),
    '#description' => t('Your Plings API key - Plings will <strong>not</strong> work without it, for more information on how to obtain one see the <a href="@url">Register for a Key</a> section of the Plings wiki.', array('@url' => 'http://www.plings.info/wiki/index.php/API_Keys#Register_for_a_Key')),
    '#default_value' => variable_get('plings_api_key', ''),
  );

  // The number of Plings to retrieve when making a call to the API.
  $form['plings_limit'] = array(
    '#type' => 'select',
    '#title' => t('Limit'),
    '#description' => t('The number of Plings to retrieve when making a call to the Plings API.'),
    '#options' => drupal_map_assoc(array(10, 20, 30, 40, 50)),
    '#default_value' => variable_get('plings_limit', 10),
  );

  // The period to retrieve Plings for.
  $form['plings_period'] = array(
    '#type' => 'select',
    '#title' => t('Period'),
    '#description' => t('The period of Plings to retrieve, 0 = Today, 1 = Today and tomorrow, 2 = Today, tomorrow and the day after, 7 = The coming week.'),
    '#options' => drupal_map_assoc(array(0, 1, 2, 3, 4, 5, 6, 7, 14, 28)),
    '#default_value' => variable_get('plings_period', 7),
  );

  // And a location detection method, how the site is identifying the location
  // of users.
  if ($location_detection_method_options = plings_get_available_handlers()) {
    // Loop through the handlers and build a supported list.
    $handlers = plings_get_location_handler_info();
    $supported = "<ul>\n";
    foreach ($handlers as $name => $handler) {
      $supported .= '<li><strong>' . check_plain($handler['name']) . '</strong> - ' . check_plain($handler['description']) . "</li>\n";
    }
    $supported .= "</ul>\n";

    // Based on the selection, further options will be displayed.
    array_unshift($location_detection_method_options, t('Please select'));
    $form['plings_location_handler'] = array(
      '#type' => 'select',
      '#title' => t('User location detection method'),
      '#description' => t('There are many ways to capture information about the location of a user in Drupal, Plings needs to know how your site does it! Currently the following methods are supported: !supported', array('!supported' => $supported)),
      '#options' => $location_detection_method_options,
      '#element_validate' => array('plings_required_select_validate'),
      '#default_value' => variable_get('plings_location_handler', ''),
    );

    // Placeholder for filter options.
    if ($plings_user_location_detection_method = variable_get('plings_location_handler', '')) {
      $filter_type_options = plings_get_location_handler_filter_options();
      array_unshift($filter_type_options, t('Please select'));
      $form['plings_filter_type'] = array(
        '#type' => 'select',
        '#title' => t('Filter type'),
        '#options' => $filter_type_options,
        '#element_validate' => array('plings_required_select_validate'),
        '#default_value' => variable_get('plings_filter_type', ''),
      );
    }
    else {
      $form['plings_filter_type'] = array(
        '#value' => '<div id="plings-filter-type"></div>',
      );
    }
  }
  else {
    drupal_set_message(t('There are no user location method handlers installed.'));
  }

  return system_settings_form($form);
}

/**
 * Validate the user location detection method dropdown.
 */
function plings_required_select_validate($element, &$form_state) {
  // Don't validate if we're resetting to defaults.
  if ($form_state['values']['op'] == t('Reset to defaults')) {
    return;
  }

  if ($element['#value'] === '0') {
    form_error($element, t('This field is required.'));
  }
}
