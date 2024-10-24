/**
 * @format
 */
// import type ReactNative = require("react-native");
import reactNative from 'react-native';
import appJson from './app.json';
import App from './app/App';
import './app/index.css';

const {AppRegistry} = reactNative;

AppRegistry.registerComponent(appJson.name, () => App);
