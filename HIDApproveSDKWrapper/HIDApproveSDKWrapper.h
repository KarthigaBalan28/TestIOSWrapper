//
//  ApproveSDKWrapper.h
//  ApproveSDKWrapper
//
//  Created by HID on 19/04/21.
//

#import <Foundation/Foundation.h>
//#import <JavaScriptCore/JavaScriptCore.h>

@protocol HIDApproveCallback <NSObject>

-(void) callWithArguments : (NSArray*) params;

@end

@interface HIDApproveSDKWrapper : NSObject
-(void)createContainer : (NSString *)activationCode withPushId :(NSString *)PushId withPwdCallBack:(id<HIDApproveCallback>)pwdCallback withExCallback: (id<HIDApproveCallback>) ExceptionCallback;
-(void)renewContainer : (NSString *)password withPwdCallBack:(id<HIDApproveCallback>)promptCallback withExceptionCallBack: (id<HIDApproveCallback>)ExceptionCallback;
-(int)getContainerRenewableDate;
-(void)setPasswordForUser : (NSString *)password;
-(NSString *)getLoginFlow : (NSString *)pushId callBack: (id<HIDApproveCallback>) genericExecutionCallback;
-(void)generateOTP : (NSString *)password  isBioEnabled : (bool) bioEnabled withSuccessCB : (id<HIDApproveCallback>)success_CB failureCB : (id<HIDApproveCallback>)failure_CB;
-(void)enableBiometrics : (NSString *)password statusCB : (id<HIDApproveCallback>)bioStatusCallback;
-(void)disableBiometrics;
-(bool)checkBioAvailability;
-(void) signTransaction : (NSString *)transactionDetails withPwdPromptCallback : (id<HIDApproveCallback>) pwdPromptCallback withSuccessCB : (id<HIDApproveCallback>) successCB withFailureCB : (id<HIDApproveCallback>) failureCB;
-(NSString *) retreiveTransaction : (NSString *)txID withPassword : (NSString *)pwd
                     isBioEnabled : (bool)isBioEnabled withCallback : (id<HIDApproveCallback>)callback;
-(void) setNotificationStatus : (NSString *) txID withStatus : (NSString *)status withPassword :pwd withJSCallback : (id<HIDApproveCallback>) onCompleteCB withPwdPromptCB : (id<HIDApproveCallback>)pwdPromptCB;
-(void)transactionCancel:(NSString *)txId withMessage:(NSString *)message withReason:(NSString *)reason withCallback:(id<HIDApproveCallback>)cancelCallback;
-(void) notifyPassword : (NSString *) password withMode : (NSString *)mode;
-(void) updatePassword : (NSString *) oldPassword newPassword : (NSString *)newPassword exceptionCallback : (id<HIDApproveCallback>)ExceptionCallback isPasswordPolicy : (bool) isPasswordPolicy;
-(void) retrievePendingNotifications : (id<HIDApproveCallback>)callback;
-(NSString *) getPasswordPolicy ;
-(void) setUsername: (NSString* )username;
-(bool) deleteContainer;
-(bool) deleteContainerWithReason:(NSString *)reason;
-(void) deleteContainerWithAuth : (NSString *)pwd withCallback : (id<HIDApproveCallback>) callback;
-(void) deleteContainerWithAuthWithReason : (NSString *)pwd withReason: (NSString *)reason withCallback : (id<HIDApproveCallback>) callback;
-(void) verifyPassword : (NSString *) pwd isBioEnabled : (bool) isBioEnabled withCallback : (id<HIDApproveCallback>) callback;
-(void)generateOTP : (NSString *)password  isBioEnabled : (bool) bioEnabled withSuccessCB : (id<HIDApproveCallback>)success_CB failureCB : (id<HIDApproveCallback>)failure_CB withOTPLabel : (NSString *) otpLabel;
-(void) signTransaction : (NSString *)transactionDetails withPwdPromptCallback : (id<HIDApproveCallback>) pwdPromptCallback withSuccessCB : (id<HIDApproveCallback>) successCB withFailureCB : (id<HIDApproveCallback>) failureCB  withOTPLabel : (NSString *) otpLabel;
-(NSString *) getDeviceProperty;
-(NSString *) getContainerFriendlyName;
-(NSString *) getMultiContainerFriendlyName;
-(void) setContainerFriendlyName : (NSString *)username withFriendlyName: (NSString *)friendlyName withSetNameCallback : (id<HIDApproveCallback>)setNameCallback;
-(NSString *) getLockPolicy:(NSString *)otp_Key withCode: (NSString *)code;
-(NSString *)getInfo;
-(NSString *)getKeyList;
-(void) directClientSignature : (NSString *)txMessage withKeyMode:(NSString *)keyMode withGenerateCallback:(id<HIDApproveCallback>)generateCallback;
-(void)directClientSignatureWithStatus: (NSString *)consensus withPassword:(NSString *)password withBiometricEnabled:(BOOL)isBiometricEnabled withDCSCallback:(id<HIDApproveCallback>)dcsCallback;
@end



