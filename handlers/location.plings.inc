<?php
// $Id$

/**
 * @file
 * Adds Location module support to Plings.
 */

/**
 * Return information about the handler.
 *
 * @return
 *    Array, a keyed array containing the friendly name of the handler, this
 *    appears on the Plings configuration page as an location detection method.
 */
function location_plings_info() {
  return array(
    'name' => t('Location (Location user)'),
    'description' => t('For sites using the Location (Location user) module to identify the location of users. NB. When users have more than one location, the first is used.'),
  );
}

/**
 * Return a mapped array of filter options.
 *
 * The handler needs to tell Plings what filtering options it supports, this
 * function does that by returning a keyed array were the keys are the
 * supported Plings filter options and the values are the names the handler
 * uses internally.
 *
 * When a request to the Plings API is made, the 'handler_name_filter_value'
 * function will be called with the handlers internal filter option name and
 * the account of the user being passed in.
 *
 * @return
 *    Array, keyed on Plings supported filter options.
 */
function location_plings_filter_options() {
  return array(
    'postcode' => 'postal_code',
    'town' => 'city',
  );
}

/**
 * Return the filter value for the requested filter option.
 *
 * @param $filter_option
 *    String, the filter option this handler is using.
 * @param $account
 *    Object, a Drupal account as returned by user_load().
 *
 * @return
 *    String, the filter value to use.
 */
function location_plings_filter_value($filter_option, $account) {
  return isset($account->location[$filter_option]) ? $account->location[$filter_option] : '';
}