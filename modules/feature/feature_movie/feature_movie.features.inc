<?php
/**
 * @file
 * feature_movie.features.inc
 */

/**
 * Implements hook_node_info().
 */
function feature_movie_node_info() {
  $items = array(
    'movie' => array(
      'name' => t('movie'),
      'base' => 'node_content',
      'description' => t('Interface to add a new movie content.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
