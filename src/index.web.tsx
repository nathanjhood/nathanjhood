/**
 * @transform
 */

import type WV = require('web-vitals');
import type ReactDOM = require('react-dom/client');
import React = require('react');
import Redux = require('react-redux');
import App = require('./App');
import appJson = require('../app.json');
import { store } from './app/store';
import './index.css';
import reportWebVitals = require('./reportWebVitals');
import reactDOM = require('react-dom/client');
import env = require('env');

declare namespace RunWebApp {
  type Options = {
    env?: 'development' | 'production' | 'test' | string;
    vitals?: boolean;
    vitalsReporter: WV.ReportCallback;
  }
}

interface RunWebApp {
  (): void;
  (options: RunWebApp.Options): void;
}

const RunWebApp = (options: RunWebApp.Options = {
  env: "development",
  vitals: true,
  vitalsReporter: console.info
}): Promise<void> => {

  return new Promise<void>((onResolved, onRejected) => {
    // Find the tag <div id="root"> in the HTML file...
    const container: HTMLElement | null = document.getElementById('root');

    if (container === null) return onRejected("Root element with ID 'root' was not found in the document. Ensure there is a corresponding HTML element with the ID 'root' in your HTML file.");

    const extStyles: HTMLLinkElement = document.createElement<'link'>('link');
    extStyles.href = env['PUBLIC_URL'] + 'static/css/index.css';
    extStyles.rel = 'stylesheet';
    document.head.appendChild<HTMLLinkElement>(extStyles);

    //
    const root: ReactDOM.Root = reactDOM.createRoot(container);

    //
    root.render(
      <React.StrictMode>
        <Redux.Provider store={store}>
          <App />
        </Redux.Provider>
      </React.StrictMode>
    );


    // If you want to start measuring performance in your app, pass a function
    // to log results (for example: reportWebVitals(console.log))
    // or send to an analytics endpoint. Learn more: https://bit.ly/CRA-vitals
    if (options.vitals) {
      reportWebVitals(options.vitalsReporter);
    };

    //
    return onResolved()
  });

};

export = RunWebApp({                        // Options:
  env: env['NODE_ENV'] || "development",    // Specify which environment is currently running.
  vitals: true,                             // Activate or de-activate web vitals here.
  vitalsReporter: console.info              // Choose a function to report web vitals with.
})
  .then(
    (result) => { console.info(appJson); return result; },
    (error) => { console.error(error); throw error; }
  )
  .catch(
    (error) => { console.error(error); throw error; }
  );
