/**
 * @file metro.config.mjs
 * @author Nathan J. Hood <nathanjhood@googlemail.com>
 * @brief
 * @version 0.1.0
 * @date 2024-09-05
 *
 * @copyright Copyright (c) 2024
 *
 */

const metroConfig = require('@react-native/metro-config');

const {getDefaultConfig, mergeConfig} = metroConfig;
/**
 * Metro configuration
 * https://reactnative.dev/docs/metro
 *
 * @type {import('metro-config').MetroConfig}
 */
const config = mergeConfig(getDefaultConfig(__dirname), {
  /* your config */
});

module.exports = config;
