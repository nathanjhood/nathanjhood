import type ReactNative = require("react-native");
import reactNative = require("react-native");
import appJson = require('../app.json');


const App = () => {
  const {
    SafeAreaView,
    ScrollView,
    Text,
    View,
    Pressable,
    StyleSheet,
    useWindowDimensions,
    useColorScheme,
  }: typeof ReactNative = reactNative;

  const { width, height } = useWindowDimensions();

  const colorScheme = useColorScheme();

  const colorBlack = "#000000";
  const colorWhite = "#FFFFFF";

  const bgColorResponsive = colorScheme === "light" ? colorWhite : colorBlack;
  const colorResponsive = colorScheme === "light" ? colorBlack : colorWhite;
  return (
    <ScrollView style={[StyleSheet.absoluteFill]}>
    </ScrollView>
  )
}


export = App;

