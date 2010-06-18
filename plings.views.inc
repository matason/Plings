<?php
// $Id$

/**
 * @file
 * Provide views data and handlers for the Plings module.
 */

/**
 * Implementation of hook_views_data().
 */
function plings_views_data() {
  $data['plings']['table']['group'] = t('Plings');

  $data['plings']['table']['base'] = array(
    'field' => 'aid',
    'title' => t('Plings'),
    'help' => t('Contains Plings activity details.'),
    'weight' => -10,
  );

  $data['plings']['aid'] = array(
    'title' => t('Activity ID'),
    'help' => t('Unique activity ID.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );

  $data['plings']['uid'] = array(
    'title' => t('User ID'),
    'help' => t('UID of the current logged in user.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_user_current',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_user_uid',
    ),
  );

  $data['plings']['vid'] = array(
    'title' => t('Activity venue ID'),
    'help' => t('ID of the venue where this activity takes place.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );

  $data['plings']['pid'] = array(
    'title' => t('Activity provider ID'),
    'help' => t('ID of the provider of the activity.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );

  $data['plings']['name'] = array(
    'title' => t('Activity name'),
    'help' => t('Name of the activity.'),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['plings']['starts'] = array(
    'title' => t('Activity starts'),
    'help' => t('Activity start date and time.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_date',
    ),
  );

  $data['plings']['ends'] = array(
    'title' => t('Activity ends'),
    'help' => t('Activity end date and time.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_date',
    ),
  );

  $data['plings']['details'] = array(
    'title' => t('Activity details'),
    'help' => t('Details of the activity.'),
    'field' => array(
      'handler' => 'views_handler_field_markup',
      'format' => FILTER_FORMAT_DEFAULT,
    ),
  );

  $data['plings']['cost'] = array(
    'title' => t('Activity cost'),
    'help' => t('Cost of the activity.'),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_float',
    ),
  );

  $data['plings']['contact'] = array(
    'title' => t('Activity contact'),
    'help' => t('Contact name for this activity.'),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
  );

  $data['plings']['phone'] = array(
    'title' => t('Activity contact phone number'),
    'help' => t('Phone number of the contact for this activity.'),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
  );

  $data['plings']['mail'] = array(
    'title' => t('Activity contact email address'),
    'help' => t('Email address of the contact for this activity.'),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
  );

  $data['plings_venue']['table']['group'] = t('Plings');

  $data['plings_venue']['table']['join'] = array(
    'plings' => array(
      'left_field' => 'vid',
      'field' => 'vid',
    ),
  );

  $data['plings_venue']['vid'] = array(
    'title' => t('Venue ID'),
    'help' => t('Unique venue ID.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );

  $data['plings_venue']['name'] = array(
    'title' => t('Venue name'),
    'help' => t('Venue name.'),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['plings_venue']['building'] = array(
    'title' => t('Venue building name or number'),
    'help' => t('Building name or number.'),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
  );

  $data['plings_venue']['street'] = array(
    'title' => t('Venue street'),
    'help' => t('Venue street.'),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
  );

  $data['plings_venue']['town'] = array(
    'title' => t('Venue town'),
    'help' => t('Venue town.'),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
  );

  $data['plings_venue']['post_town'] = array(
    'title' => t('Venue post town'),
    'help' => t('Venue post town.'),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
  );

  $data['plings_venue']['county'] = array(
    'title' => t('Venue county'),
    'help' => t('Venue county.'),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
  );

  $data['plings_venue']['postcode'] = array(
    'title' => t('Venue postcode'),
    'help' => t('Venue postcode.'),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
  );

  $data['plings_venue']['phone'] = array(
    'title' => t('Venue phone number'),
    'help' => t('Venue phone number.'),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
  );

  $data['plings_venue']['place_link'] = array(
    'title' => t('Venue place link'),
    'help' => t('Venue Plings place link.'),
    'field' => array(
      'handler' => 'views_handler_field_url',
    ),
  );

  $data['plings_provider']['table']['group'] = t('Plings');

  $data['plings_provider']['table']['join'] = array(
    'plings' => array(
      'left_field' => 'pid',
      'field' => 'pid',
    ),
  );

  $data['plings_provider']['pid'] = array(
    'title' => t('PID'),
    'help' => t('Unique provider ID.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );

  $data['plings_provider']['name'] = array(
    'title' => t('Provider name'),
    'help' => t('Provider name.'),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['plings_provider']['description'] = array(
    'title' => t('Provider description'),
    'help' => t('A description of the provider.'),
    'field' => array(
      'handler' => 'views_handler_field_markup',
      'format' => FILTER_FORMAT_DEFAULT,
    ),
  );

  $data['plings_provider']['website'] = array(
    'title' => t("Provider's website"),
    'help' => t("The provider's website."),
    'field' => array(
      'handler' => 'views_handler_field_url',
    ),
  );

  $data['plings_provider']['contact'] = array(
    'title' => t('Provider contact'),
    'help' => t('Contact name for this provider.'),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
  );

  $data['plings_provider']['phone'] = array(
    'title' => t('Provider contact phone number'),
    'help' => t('Phone number of the contact at this provider.'),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
  );

  $data['plings_provider']['mail'] = array(
    'title' => t('Provider contact email address'),
    'help' => t('Email address of the contact at this provider.'),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
  );

  return $data;
}