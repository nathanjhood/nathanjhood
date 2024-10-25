// @ts-check

import React from 'react';
import {AppRegistry} from 'react-native';
import {Provider} from 'react-redux';
import {name as appName} from './app.json';
import App from './src/App';
import {store} from './src/app/store';

AppRegistry.registerComponent(appName, () => () => (
  <React.StrictMode>
    <Provider store={store}>
      <App />
    </Provider>
  </React.StrictMode>
));
