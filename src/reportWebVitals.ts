import type WV = require("web-vitals");

// function logDelta({name, id, delta}: WV.MetricType): void {
//   console.info(`${name} matching ID ${id} changed by ${delta}`);
// }

const reportWebVitals = (onPerfEntry?: WV.ReportCallback): void => {

  if (onPerfEntry && typeof onPerfEntry === 'function') {
    import("web-vitals").then(({ onCLS, onFID, onFCP, onLCP, onTTFB }) => {
      onCLS(onPerfEntry)
      onFID(onPerfEntry)
      onFCP(onPerfEntry)
      onLCP(onPerfEntry)
      onTTFB(onPerfEntry)
    }).catch((e) => console.error(e))
  }
}

export = reportWebVitals;
