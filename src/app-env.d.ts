/* eslint-disable @typescript-eslint/triple-slash-reference */
/// <reference types="node" />
/// <reference types="react" />
/// <reference types="react-dom" />

declare module "*.avif" {
  const src: string;
  export default src;
}

declare module "*.bmp" {
  const src: string;
  export default src;
}

declare module "*.gif" {
  const src: string;
  export default src;
}

declare module "*.jpg" {
  const src: string;
  export default src;
}

declare module "*.jpeg" {
  const src: string;
  export default src;
}

declare module "*.png" {
  const src: string;
  export default src;
}

declare module "*.webp" {
  const src: string;
  export default src;
}

declare module "*.svg" {
  import * as React from "react";

  export const ReactComponent: React.FunctionComponent<
    React.SVGProps<SVGSVGElement> & { title?: string }
  >;

  const src: string;
  export default src;
}

declare module "*.module.css" {
  /** **Experimental:** Import styles that can be used with `react-native-web` components, using the `style` prop. */
  export const unstable_styles: { readonly [key: string]: object };

  const classes: { readonly [key: string]: string };
  export default classes;
}

declare module "*.module.sass" {
  /** **Experimental:** Import styles that can be used with `react-native-web` components, using the `style` prop. */
  export const unstable_styles: { readonly [key: string]: object };

  const classes: { readonly [key: string]: string };
  export default classes;
}

declare module "*.module.scss" {
  /** **Experimental:** Import styles that can be used with `react-native-web` components, using the `style` prop. */
  export const unstable_styles: { readonly [key: string]: object };

  const classes: { readonly [key: string]: string };
  export default classes;
}

// Allow for css imports, but don't export anything
declare module "*.css";
declare module "*.sass";
declare module "*.scss";

declare module "env" {
  const env: { readonly [key: string]: string }; // NodeJS.ProcessEnv
  export = env;
}

// from redux React Native template

// declare module "*.gif" {
//   const logo: number
//   export default logo
// }

declare module "react-native/Libraries/NewAppScreen" {
  import type { FC } from "react";
  export const HermesBadge: FC
}

declare module "react-native/Libraries/Core/Devtools/openURLInBrowser" {
  export default function openURLInBrowser(url: string): void
}
