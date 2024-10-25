import './App.css';
import Counter from './features/counter/Counter';
import Quotes from './features/quotes/Quotes';
import logo from './logo.svg';

declare namespace App {
  type Component = JSX.Element | null;
}

interface App {
  (): App.Component;
}

const App: App = (): App.Component => {
  return (
    <div className="App">
      <header className="App-header">
        <img
          src={'data:image/svg+xml;base64,' + logo}
          className="App-logo"
          alt="logo"
        />
        <Counter />
        <p>
          Edit <code>src/App.tsx</code> and save to reload.
        </p>
        <Quotes />
        <span>
          <span>Learn </span>
          <a
            className="App-link"
            href="https://reactjs.org"
            target="_blank"
            rel="noopener noreferrer">
            React
          </a>
          <span>, </span>
          <a
            className="App-link"
            href="https://redux.js.org"
            target="_blank"
            rel="noopener noreferrer">
            Redux
          </a>
          <span>, </span>
          <a
            className="App-link"
            href="https://redux-toolkit.js.org"
            target="_blank"
            rel="noopener noreferrer">
            Redux Toolkit
          </a>
          <span>, </span>
          <a
            className="App-link"
            href="https://react-redux.js.org"
            target="_blank"
            rel="noopener noreferrer">
            React Redux
          </a>
          ,<span> and </span>
          <a
            className="App-link"
            href="https://reselect.js.org"
            target="_blank"
            rel="noopener noreferrer">
            Reselect
          </a>
        </span>
      </header>
    </div>
  ) satisfies JSX.Element;
};

export = App;

// import type ReactNative = require("react-native");
// import reactNative = require("react-native");
// import appJson = require('../app.json');

// const App = () => {
//   const {
//     SafeAreaView,
//     ScrollView,
//     Text,
//     View,
//     Pressable,
//     StyleSheet,
//     useWindowDimensions,
//     useColorScheme,
//   }: typeof ReactNative = reactNative;

//   const { width, height } = useWindowDimensions();

//   const colorScheme = useColorScheme();

//   const colorBlack = "#000000";
//   const colorWhite = "#FFFFFF";

//   const bgColorResponsive = colorScheme === "light" ? colorWhite : colorBlack;
//   const colorResponsive = colorScheme === "light" ? colorBlack : colorWhite;
//   return (
//     <ScrollView style={[StyleSheet.absoluteFill]}>
//       <Text>Wanking</Text>
//     </ScrollView>
//   )
// }

// export = App;

// const KeysApp = () => {
//     const {
//     SafeAreaView,
//     ScrollView,
//     Text,
//     View,
//     Pressable,
//     StyleSheet,
//     useWindowDimensions,
//     useColorScheme,
//   }: typeof ReactNative = reactNative;

//   const { width, height } = useWindowDimensions();

//   const colorScheme = useColorScheme();

//   const colorBlack = "#000000";
//   const colorWhite = "#FFFFFF";

//   const bgColorResponsive = colorScheme === "light" ? colorWhite : colorBlack;
//   const colorResponsive = colorScheme === "light" ? colorBlack : colorWhite;
//   return (
//     <ScrollView style={[{
//       // backgroundColor: bgColorResponsive,
//       display: "flex",
//     }, StyleSheet.absoluteFill]}
//     >
//       <SafeAreaView
//         style={[{
//           backgroundColor: bgColorResponsive
//         }]}
//       >
//         <View>
//           <Text style={{color: colorResponsive }}>
//             <Text>{ appJson.displayName }</Text>
//           </Text>
//         </View>
//         <View>
//           <Pressable style={{ backgroundColor: "#FFFFFF", borderWidth: StyleSheet.hairlineWidth }}>
//             <Text style={{ color: "#000000", alignSelf: "flex-end" }} >C</Text>
//           </Pressable>
//           <Pressable style={{ backgroundColor: "#000000", width: width * 0.5, alignSelf: "flex-end" }}>
//             <Text style={{ color: "#FFFFFF", alignSelf: "flex-end" }} >C#</Text>
//           </Pressable>
//           <Pressable style={{ backgroundColor: "#FFFFFF", borderWidth: StyleSheet.hairlineWidth }}>
//             <Text style={{ color: colorResponsive, alignSelf: "flex-end" }} >D</Text>
//           </Pressable>
//           <Pressable style={{ backgroundColor: "#000000", width: width * 0.5, alignSelf: "flex-end" }}>
//             <Text style={{ color: "#FFFFFF", alignSelf: "flex-end" }}>D#</Text>
//           </Pressable>
//           <Pressable style={{ backgroundColor: "#FFFFFF", borderWidth: StyleSheet.hairlineWidth }}>
//             <Text style={{ color: "#000000", alignSelf: "flex-end" }} >E</Text>
//           </Pressable>
//           <Pressable style={{ backgroundColor: "#FFFFFF", borderWidth: StyleSheet.hairlineWidth }}>
//             <Text style={{ color: "#000000", alignSelf: "flex-end" }} >F</Text>
//           </Pressable>
//           <Pressable style={{ backgroundColor: "#000000", width: width * 0.5, alignSelf: "flex-end" }}>
//             <Text style={{ color: "#FFFFFF", alignSelf: "flex-end" }}>F#</Text>
//           </Pressable>
//           <Pressable style={{ backgroundColor: "#FFFFFF", borderWidth: StyleSheet.hairlineWidth }}>
//             <Text style={{ color: "#000000", alignSelf: "flex-end" }} >G</Text>
//           </Pressable>
//           <Pressable style={{ backgroundColor: "#000000", width: width * 0.5, alignSelf: "flex-end" }}>
//             <Text style={{ color: "#FFFFFF", alignSelf: "flex-end" }} >G#</Text>
//           </Pressable>
//           <Pressable style={{ backgroundColor: "#FFFFFF", borderWidth: StyleSheet.hairlineWidth }}>
//             <Text style={{ color: "#000000", alignSelf: "flex-end" }} >A</Text>
//           </Pressable>
//           <Pressable style={{ backgroundColor: "#000000", width: width * 0.5, alignSelf: "flex-end" }}>
//             <Text style={{ color: "#FFFFFF", alignSelf: "flex-end" }} >A#</Text>
//           </Pressable>
//           <Pressable style={{ backgroundColor: "#FFFFFF", borderWidth: StyleSheet.hairlineWidth }}>
//             <Text style={{ color: "#000000", alignSelf: "flex-end" }} >B</Text>
//           </Pressable>
//         </View>
//       </SafeAreaView>
//     </ScrollView>
//   )
// }

// const OldApp = () => {

//   const {
//     SafeAreaView,
//     ScrollView,
//     Text,
//     Pressable,
//     StyleSheet,
//     useWindowDimensions,
//     useColorScheme,
//   }: typeof ReactNative = reactNative;

//   const { width, height } = useWindowDimensions();

//   const colorScheme = useColorScheme();

//   const colorBlack = "#000000";
//   const colorWhite = "#FFFFFF";

//   const bgColorResponsive = colorScheme === "light" ? colorWhite : colorBlack;
//   const colorResponsive = colorScheme === "light" ? colorBlack : colorWhite;

//   const styles = StyleSheet.create<{
//     body: ReactNative.ViewStyle,
//     p: ReactNative.TextStyle
//   }>({
//     body: {
//       backgroundColor: bgColorResponsive,
//       display: "flex",
//       margin: 0,
//       minHeight: height
//     },
//     p: {
//       color: colorResponsive,
//     }
//   });

//   return (
//     <ScrollView style={[styles.body, StyleSheet.absoluteFill]}>
//       <SafeAreaView
//         style={{
//           display: "flex",
//           alignItems: "center",
//           justifyContent: "center",
//         }}
//       >
//         <Text style={styles.p}>
//           <Text>This was hard boiii</Text>
//         </Text>
//         <Pressable
//           style={{
//             display: "flex",
//             alignItems: "center",
//             justifyContent: "center",
//             backgroundColor: "#AAAAAA",
//             width: width * 0.5,
//             height: width * 0.5,
//             borderRadius: 5
//           }}
//           onPress={(event) => {
//             console.log("ouch, quit it!", new Date(event.timeStamp).toUTCString())
//           }}
//         >
//           <Text>Click</Text>
//         </Pressable>
//       </SafeAreaView>
//     </ScrollView>
//   );
// };
