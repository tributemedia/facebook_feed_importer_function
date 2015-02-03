<?php
/**
 * @file
 * facebook_feed_importer_function.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function facebook_feed_importer_function_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function facebook_feed_importer_function_node_info() {
  $items = array(
    'facebook_feed' => array(
      'name' => t('Facebook Feed'),
      'base' => 'node_content',
      'description' => t('News Feed from Tribute Media\'s facebook page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
