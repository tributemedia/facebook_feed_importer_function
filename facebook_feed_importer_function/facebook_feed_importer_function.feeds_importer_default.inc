<?php
/**
 * @file
 * facebook_feed_importer_function.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function facebook_feed_importer_function_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'facebook_feed_importer';
  $feeds_importer->config = array(
    'name' => 'Facebook Feed Importer',
    'description' => 'Importer for FaceBook Feeds',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsJSONPathParser',
      'config' => array(
        'context' => '$.data.*',
        'sources' => array(
          'jsonpath_parser:0' => 'id',
          'jsonpath_parser:1' => 'message',
          'jsonpath_parser:2' => 'message, story, caption',
          'jsonpath_parser:3' => 'from.category_list.*.name',
          'jsonpath_parser:4' => 'created_time',
          'jsonpath_parser:5' => 'id',
          'jsonpath_parser:6' => 'icon',
          'jsonpath_parser:7' => 'likes.data.*.name',
          'jsonpath_parser:8' => 'link',
          'jsonpath_parser:9' => 'picture',
          'jsonpath_parser:10' => 'type',
          'jsonpath_parser:11' => 'message',
          'jsonpath_parser:12' => 'shares.count',
          'jsonpath_parser:13' => 'name',
          'jsonpath_parser:14' => 'caption',
          'jsonpath_parser:15' => 'to.data.*.name',
          'jsonpath_parser:16' => 'message_tags.*.*.name',
          'jsonpath_parser:17' => 'from.name',
          'jsonpath_parser:18' => 'story',
          'jsonpath_parser:19' => 'object_id',
          'jsonpath_parser:20' => 'created_time',
        ),
        'debug' => array(
          'options' => array(
            'context' => 0,
            'jsonpath_parser:0' => 0,
            'jsonpath_parser:1' => 0,
            'jsonpath_parser:2' => 0,
            'jsonpath_parser:3' => 0,
            'jsonpath_parser:4' => 0,
            'jsonpath_parser:5' => 0,
            'jsonpath_parser:6' => 0,
            'jsonpath_parser:7' => 0,
            'jsonpath_parser:8' => 0,
            'jsonpath_parser:9' => 0,
            'jsonpath_parser:10' => 0,
            'jsonpath_parser:11' => 0,
            'jsonpath_parser:12' => 0,
            'jsonpath_parser:13' => 0,
            'jsonpath_parser:14' => 0,
            'jsonpath_parser:15' => 0,
            'jsonpath_parser:16' => 0,
            'jsonpath_parser:17' => 0,
            'jsonpath_parser:18' => 0,
            'jsonpath_parser:19' => 0,
            'jsonpath_parser:20' => 0,
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'facebook_feed',
        'expire' => '2592000',
        'author' => 0,
        'authorize' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'jsonpath_parser:0',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'jsonpath_parser:1',
            'target' => 'body',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'jsonpath_parser:2',
            'target' => 'title',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'jsonpath_parser:3',
            'target' => 'field_facebook_categories',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'jsonpath_parser:4',
            'target' => 'field_facebook_created_date',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'jsonpath_parser:5',
            'target' => 'field_facebook_id',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'jsonpath_parser:6',
            'target' => 'field_facebook_icon',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'jsonpath_parser:7',
            'target' => 'field_facebook_likes',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'jsonpath_parser:8',
            'target' => 'field_facebook_link',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'jsonpath_parser:9',
            'target' => 'field_facebook_pictures',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'jsonpath_parser:10',
            'target' => 'field_facebook_type',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'jsonpath_parser:11',
            'target' => 'field_facebook_message',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'jsonpath_parser:12',
            'target' => 'field_facebook_shares',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'jsonpath_parser:13',
            'target' => 'field_facebook_name',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'jsonpath_parser:14',
            'target' => 'field_facebook_caption',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'jsonpath_parser:15',
            'target' => 'field_facebook_to',
            'unique' => FALSE,
          ),
          16 => array(
            'source' => 'jsonpath_parser:16',
            'target' => 'field_facebook_tags',
            'unique' => FALSE,
          ),
          17 => array(
            'source' => 'jsonpath_parser:17',
            'target' => 'field_facebook_screen_name',
            'unique' => FALSE,
          ),
          18 => array(
            'source' => 'jsonpath_parser:18',
            'target' => 'field_facebook_story',
            'unique' => FALSE,
          ),
          19 => array(
            'source' => 'jsonpath_parser:19',
            'target' => 'field_facebook_object_id',
            'unique' => FALSE,
          ),
          20 => array(
            'source' => 'jsonpath_parser:20',
            'target' => 'field_facebook_date:start',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '0',
        'input_format' => 'full_html',
        'skip_hash_check' => 0,
      ),
    ),
    'content_type' => 'facebook_feed',
    'update' => 0,
    'import_period' => '0',
    'expire_period' => 3600,
    'import_on_create' => 0,
    'process_in_background' => 0,
  );
  $export['facebook_feed_importer'] = $feeds_importer;

  return $export;
}
