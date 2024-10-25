/** @type {Pick<import('metro-config'), 'mergeConfig'> & { getDefaultConfig: import('metro-config').getDefaultConfig }} */
const {mergeConfig, getDefaultConfig} = require('@react-native/metro-config');

/**
 * Metro configuration
 * https://reactnative.dev/docs/metro
 *
 * @type {import('metro-config').MetroConfig}
 */
const config = {
  /* your config */
};

module.exports = mergeConfig(getDefaultConfig(__dirname), config);
