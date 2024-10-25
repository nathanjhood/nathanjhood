import NewAppScreen = require("react-native/Libraries/NewAppScreen")

interface AllColors {
  primary: string
  white: string
  lighter: string
  light: string
  dark: string
  darker: string
  black: string
}

const TypedColors: AllColors = NewAppScreen.Colors as AllColors

export = TypedColors;
