
"use strict";

let SetupCameraStream = require('./SetupCameraStream.js')
let SetHardSync = require('./SetHardSync.js')
let StereoVGASubscription = require('./StereoVGASubscription.js')
let MissionWpUpload = require('./MissionWpUpload.js')
let Activation = require('./Activation.js')
let MissionWpGetInfo = require('./MissionWpGetInfo.js')
let SDKControlAuthority = require('./SDKControlAuthority.js')
let MissionHpUpdateYawRate = require('./MissionHpUpdateYawRate.js')
let MFIOConfig = require('./MFIOConfig.js')
let MissionHpAction = require('./MissionHpAction.js')
let MissionHpUpload = require('./MissionHpUpload.js')
let MissionHpGetInfo = require('./MissionHpGetInfo.js')
let MissionHpResetYaw = require('./MissionHpResetYaw.js')
let MissionWpAction = require('./MissionWpAction.js')
let MissionHpUpdateRadius = require('./MissionHpUpdateRadius.js')
let MissionWpSetSpeed = require('./MissionWpSetSpeed.js')
let StereoDepthSubscription = require('./StereoDepthSubscription.js')
let QueryDroneVersion = require('./QueryDroneVersion.js')
let SendMobileData = require('./SendMobileData.js')
let Stereo240pSubscription = require('./Stereo240pSubscription.js')
let SetLocalPosRef = require('./SetLocalPosRef.js')
let MissionWpGetSpeed = require('./MissionWpGetSpeed.js')
let MissionStatus = require('./MissionStatus.js')
let DroneArmControl = require('./DroneArmControl.js')
let CameraAction = require('./CameraAction.js')
let DroneTaskControl = require('./DroneTaskControl.js')
let MFIOSetValue = require('./MFIOSetValue.js')

module.exports = {
  SetupCameraStream: SetupCameraStream,
  SetHardSync: SetHardSync,
  StereoVGASubscription: StereoVGASubscription,
  MissionWpUpload: MissionWpUpload,
  Activation: Activation,
  MissionWpGetInfo: MissionWpGetInfo,
  SDKControlAuthority: SDKControlAuthority,
  MissionHpUpdateYawRate: MissionHpUpdateYawRate,
  MFIOConfig: MFIOConfig,
  MissionHpAction: MissionHpAction,
  MissionHpUpload: MissionHpUpload,
  MissionHpGetInfo: MissionHpGetInfo,
  MissionHpResetYaw: MissionHpResetYaw,
  MissionWpAction: MissionWpAction,
  MissionHpUpdateRadius: MissionHpUpdateRadius,
  MissionWpSetSpeed: MissionWpSetSpeed,
  StereoDepthSubscription: StereoDepthSubscription,
  QueryDroneVersion: QueryDroneVersion,
  SendMobileData: SendMobileData,
  Stereo240pSubscription: Stereo240pSubscription,
  SetLocalPosRef: SetLocalPosRef,
  MissionWpGetSpeed: MissionWpGetSpeed,
  MissionStatus: MissionStatus,
  DroneArmControl: DroneArmControl,
  CameraAction: CameraAction,
  DroneTaskControl: DroneTaskControl,
  MFIOSetValue: MFIOSetValue,
};
